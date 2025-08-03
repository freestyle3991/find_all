//
//  MapSearchDialog.swift
//  YandexMapLUDITO
//
//  Created by Muhammadjon Kuvandikov on 01/08/25.
//


import UIKit
import SnapKit
import YandexMapsMobile
import CoreLocation

class MapSearchDialog: UIViewController {
    
    var onAction: ((YMKSuggestItem?) -> Void)?
    
    private var currentLocation: CLLocation?
    private let curtainView = UIView()
    private var suggestResults: [YMKSuggestItem] = []
    private let searchManager = YMKSearch.sharedInstance().createSearchManager(with: .combined)
    private var suggestSession: YMKSearchSuggestSession!
    private let SUGGEST_OPTIONS = YMKSuggestOptions()
    
    private let tableView = UITableView()
    private let containerView = UIView()
    private let contentStackView = UIStackView()
    private let dimmedView = UIView()
    
    private var searchView: SearchMapView!
    
    // Constants
    private let maxDimmedAlpha: CGFloat = 0.6
    private let defaultHeight: CGFloat = windowHeightA * 0.73
    private let dismissibleHeight: CGFloat = 400
    private let maximumContainerHeight: CGFloat = UIScreen.main.bounds.height - 50
    private var currentContainerHeight: CGFloat = windowHeightA * 0.73
    
    // Dynamic Constraints
    private var containerViewHeightConstraint: Constraint?
    private var containerViewBottomConstraint: Constraint?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        setupData()
        suggestSession = searchManager.createSuggestSession()
        setupViews()
        setupConstraints()
        setupPanGesture()
        
        let tapGesture = UITapGestureRecognizer(target: self, action: #selector(handleCloseAction))
        dimmedView.addGestureRecognizer(tapGesture)
    }
   
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        animateShowDimmedView()
        animatePresentContainer()
    }
    
    private func setupData() {
        if let location = CLLocationManager().location {
            self.currentLocation = location
        }
        NotificationCenter.default.addObserver(self, selector: #selector(keyboardWillShow(_:)), name: UIResponder.keyboardWillShowNotification, object: nil)
        NotificationCenter.default.addObserver(self, selector: #selector(keyboardWillHide(_:)), name: UIResponder.keyboardWillHideNotification, object: nil)
    }
    
    deinit {
            NotificationCenter.default.removeObserver(self)
        }
    
    @objc private func handleCloseAction() {
        animateDismissView()
    }
    
    @objc private func keyboardWillShow(_ notification: Notification) {
        guard let userInfo = notification.userInfo,
              let keyboardFrame = userInfo[UIResponder.keyboardFrameEndUserInfoKey] as? CGRect else { return }
        
        let bottomInset = keyboardFrame.height
        tableView.contentInset.bottom = bottomInset + 16
        tableView.scrollIndicatorInsets.bottom = bottomInset + 16
    }

    @objc private func keyboardWillHide(_ notification: Notification) {
        tableView.contentInset.bottom = 0
        tableView.scrollIndicatorInsets.bottom = 0
    }
}

// MARK: - Setup Views & Constraints
extension MapSearchDialog {
    
    private func setupViews() {
        view.backgroundColor = .clear
        
        dimmedView.backgroundColor = .black
        dimmedView.alpha = maxDimmedAlpha
        view.addSubview(dimmedView)
        
        containerView.backgroundColor = UIColor(hex: "#F9F9F9")
        containerView.layer.cornerRadius = 20
        containerView.clipsToBounds = true
        view.addSubview(containerView)
        
        // Curtain (drag handle)
        curtainView.backgroundColor = .lightGray
        curtainView.layer.cornerRadius = 2
        containerView.addSubview(curtainView)
        
        // SearchView
        searchView = SearchMapView()
        containerView.addSubview(searchView)
        searchView.onText = { [weak self] text in
            guard let self = self else { return }
            if text.count > 0 {
                self.suggestSession.suggest(
                    withText: text,
                    window: boundingBox,
                    suggestOptions: self.SUGGEST_OPTIONS
                ) { items, error in
                    self.onSuggestResponse(items ?? [])
                }
            } else {
                self.suggestResults.removeAll()
                self.tableView.reloadData()
            }
        }
        searchView.onClear = { [weak self] _ in
            self?.suggestResults.removeAll()
            self?.tableView.reloadData()
        }
        
        // TableView
        tableView.separatorStyle = .none
        tableView.backgroundColor = .clear
        tableView.delegate = self
        tableView.dataSource = self
        tableView.showsVerticalScrollIndicator = false
        tableView.contentInsetAdjustmentBehavior = .never
        tableView.register(MapSearchSuggestCell.self, forCellReuseIdentifier: "MapSearchSuggestCell")
        if #available(iOS 15.0, *) {
            tableView.sectionHeaderTopPadding = 0
        }
        
        contentStackView.axis = .vertical
        contentStackView.spacing = 10
        contentStackView.addArrangedSubview(tableView)
        containerView.addSubview(contentStackView)
    }
    
    private func setupConstraints() {
        dimmedView.snp.makeConstraints { make in
            make.edges.equalToSuperview()
        }
        
        containerView.snp.makeConstraints { make in
            make.leading.trailing.equalToSuperview()
            containerViewBottomConstraint = make.bottom.equalToSuperview().offset(defaultHeight).constraint
            containerViewHeightConstraint = make.height.equalTo(defaultHeight).constraint
        }
        
        curtainView.snp.makeConstraints { make in
            make.centerX.equalToSuperview()
            make.top.equalToSuperview().offset(10)
            make.size.equalTo(CGSize(width: 40, height: 4))
        }
        
        searchView.snp.makeConstraints { make in
            make.top.equalToSuperview().offset(28)
            make.left.right.equalToSuperview().inset(16)
            make.height.equalTo(64)
        }
        
        contentStackView.snp.makeConstraints { make in
            make.top.equalTo(searchView.snp.bottom).offset(16)
            make.left.right.bottom.equalToSuperview()
        }
    }
}

// MARK: TableView
extension MapSearchDialog: UITableViewDelegate, UITableViewDataSource {
    
    func numberOfSections(in tableView: UITableView) -> Int { 1 }
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        suggestResults.count
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {

        guard let cell = tableView.dequeueReusableCell(withIdentifier: "MapSearchSuggestCell", for: indexPath) as? MapSearchSuggestCell else {
            return UITableViewCell()
        }

        let model = suggestResults[indexPath.row]
        let distance: String = {
            guard let current = self.currentLocation,
                  let target = model.center else { return "" }
            
            let dest = CLLocation(latitude: target.latitude, longitude: target.longitude)
            let meters = current.distance(from: dest)

            if meters >= 1000 {
                return String(format: "%.1f km", meters / 1000)
            } else {
                return String(format: "%.0f m", meters)
            }
        }()
        cell.configure(with: model, distance: distance)
        cell.isFirst = (indexPath.row == 0)
        cell.onAction = { [weak self] model in
            self?.onAction?(model)
            self?.animateDismissView()
        }
        cell.selectionStyle = .none
        cell.backgroundColor = .clear
        return cell
    }


    func tableView(_ tableView: UITableView, heightForRowAt indexPath: IndexPath) -> CGFloat {
        UITableView.automaticDimension
    }
}

// MARK: Gesture
extension MapSearchDialog {
    
    private func setupPanGesture() {
        let panGesture = UIPanGestureRecognizer(target: self, action: #selector(handlePanGesture))
        panGesture.delaysTouchesBegan = false
        panGesture.delaysTouchesEnded = false
        view.addGestureRecognizer(panGesture)
    }

    @objc private func handlePanGesture(gesture: UIPanGestureRecognizer) {
        let translation = gesture.translation(in: view)
        let isDraggingDown = translation.y > 0
        let newHeight = currentContainerHeight - translation.y
        
        switch gesture.state {
        case .changed:
            if newHeight < maximumContainerHeight {
                containerViewHeightConstraint?.update(offset: newHeight)
                view.layoutIfNeeded()
            }
        case .ended:
            if newHeight < dismissibleHeight {
                animateDismissView()
            } else if newHeight < defaultHeight || (newHeight < maximumContainerHeight && isDraggingDown) {
                animateContainerHeight(defaultHeight)
            } else if newHeight > defaultHeight && !isDraggingDown {
                animateContainerHeight(maximumContainerHeight)
            }
        default:
            break
        }
    }
    
    private func animateContainerHeight(_ height: CGFloat) {
        UIView.animate(withDuration: 0.4) {
            self.containerViewHeightConstraint?.update(offset: height)
            self.view.layoutIfNeeded()
        }
        currentContainerHeight = height
    }
}

// MARK: - Animations
extension MapSearchDialog {
    
    private func animatePresentContainer() {
        UIView.animate(withDuration: 0.3) {
            self.containerViewBottomConstraint?.update(offset: 0)
            self.view.layoutIfNeeded()
        }
    }
    
    private func animateShowDimmedView() {
        dimmedView.alpha = 0
        UIView.animate(withDuration: 0.4) {
            self.dimmedView.alpha = self.maxDimmedAlpha
        }
    }
    
    private func animateDismissView() {
        self.view.endEditing(true)
        UIView.animate(withDuration: 0.3) {
            self.containerViewBottomConstraint?.update(offset: self.defaultHeight)
            self.view.layoutIfNeeded()
        }
        UIView.animate(withDuration: 0.4) {
            self.dimmedView.alpha = 0
        } completion: { _ in
            self.dismiss(animated: false)
        }
    }
    
    func onSuggestResponse(_ items: [YMKSuggestItem]) {
        suggestResults = items
        tableView.reloadData()
    }
    
}

