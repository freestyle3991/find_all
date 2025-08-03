//
//  MapViewController.swift
//  YandexMapLUDITO
//
//  Created by Muhammadjon Kuvandikov on 01/08/25.
//

import UIKit
import SnapKit
import YandexMapsMobile
import CoreLocation

final class MapViewController: UIViewController, YMKMapCameraListener {

    private let viewModel = MapViewModel()
    private var mapView: YMKMapView!
    private let centerIcon = UIImageView(image: UIImage(named: "location_pin_icon"))
    private let locMeButton = UIButton()
    private let bottomSheet = BottomSheetView()
    private let searchView = SearchView()
    private var scrollingEndedTimer: Timer?
    private var locMeButtonBottomConstraint: Constraint?

    private var selectedCoordinate = CLLocationCoordinate2D()

    override func viewDidLoad() {
        super.viewDidLoad()
        setupViews()
        viewModel.onLocationAvailable = { [weak self] coord in
              guard let self = self else { return }
              let target = YMKPoint(latitude: coord.latitude, longitude: coord.longitude)
              let position = YMKCameraPosition(target: target, zoom: 14, azimuth: 0, tilt: 0)
              self.mapView.mapWindow.map.move(
                  with: position,
                  animation: YMKAnimation(type: .linear, duration: 0.7)
              )
          }
        viewModel.requestLocationAccess()
    }

    private func setupViews() {
        mapView = YMKMapView()
        mapView.clipsToBounds = true
        mapView.translatesAutoresizingMaskIntoConstraints = false
        mapView.mapWindow.map.mapType = .map
        mapView.mapWindow.map.addCameraListener(with: self)
        
        centerIcon.contentMode = .scaleAspectFit

        locMeButton.setImage(UIImage(named: "current_icon"), for: .normal)
        locMeButton.backgroundColor = UIColor(hex: "#FFFFFF")
        locMeButton.layer.cornerRadius = 32
        locMeButton.layer.shadowColor = UIColor.black.cgColor
        locMeButton.layer.shadowOpacity = 0.2
        locMeButton.layer.shadowOffset = CGSize(width: 0, height: 4)
        locMeButton.layer.shadowRadius = 6
        locMeButton.layer.masksToBounds = false
        locMeButton.addTarget(self, action: #selector(centerToUser), for: .touchUpInside)
        
        bottomSheet.isHidden = true
        
        searchView.onActionPress = {
            print("searchView.onActionPress")
            let dialog = MapSearchDialog()
            dialog.onAction = { [weak self] model in
                guard let self = self, let model = model, let center = model.center else { return }
                    let point = YMKPoint(latitude: center.latitude, longitude: center.longitude)
                    let position = YMKCameraPosition(target: point, zoom: 14, azimuth: 0, tilt: 0)
                    self.mapView.mapWindow.map.move(
                        with: position,
                        animation: YMKAnimation(type: .smooth, duration: 0.7),
                        cameraCallback: { _ in
                            let title = model.displayText ?? model.title.text
                            let subtitle = model.subtitle?.text ?? ""
                            self.bottomSheet.update(title: title, subtitle: subtitle)

                            DispatchQueue.main.asyncAfter(deadline: .now() + 0.3) {
                                self.showBottomSheetAnimated()
                            }
                            self.selectedCoordinate = CLLocationCoordinate2D(latitude: center.latitude, longitude: center.longitude)
                        }
                    )
            }
            dialog.modalPresentationStyle = .overCurrentContext
            self.present(dialog, animated: false)
        }
        
        bottomSheet.onAction = { [weak self] action in
            switch action {
            case 0:
                self?.hideBottomSheetAnimated()
                
            case 1:
                let alert = UIAlertController(title: "Добавить адрес в избранное",
                                              message: self?.bottomSheet.getSubtitle(),
                                              preferredStyle: .alert)
                
                let cancel = UIAlertAction(title: "Отмена", style: .destructive, handler: nil)
                let confirm = UIAlertAction(title: "Подтвердить", style: .default) { _ in

                    let model = MapLocationModel(
                        title: self?.bottomSheet.getTitle() ?? "",
                        subtitle: self?.bottomSheet.getSubtitle() ?? "",
                        coordinate: self?.selectedCoordinate ?? CLLocationCoordinate2D(),
                        id: Int(Date().timeIntervalSince1970)
                    )
                    FavoritesStorage.add(item: model)
                    print("SavedToFavorites \(model)")
                    
                    let successAlert = UIAlertController(title: nil, message: "Успешно добавлено", preferredStyle: .alert)
                       self?.present(successAlert, animated: true)

                    DispatchQueue.main.asyncAfter(deadline: .now() + 0.8) {
                           successAlert.dismiss(animated: true)
                       }
                }
                
                alert.addAction(confirm)
                alert.addAction(cancel)
                self?.present(alert, animated: true)
                
            default: break
            }
        }
        
        view.addSubview(mapView)
        view.addSubview(centerIcon)
        view.addSubview(locMeButton)
        view.addSubview(bottomSheet)
        view.addSubview(searchView)
        
        mapView.snp.makeConstraints { make in
            make.edges.equalToSuperview()
        }

        centerIcon.snp.makeConstraints { make in
            make.centerX.equalToSuperview()
            make.centerY.equalToSuperview().offset(-36)
            make.size.equalTo(64)
        }

        locMeButton.snp.makeConstraints { make in
            make.size.equalTo(64)
            make.trailing.equalToSuperview().inset(16)
            self.locMeButtonBottomConstraint = make.bottom.equalToSuperview().inset(windowTabBarHeight + 32).constraint
        }
        
        searchView.snp.makeConstraints { make in
            make.top.equalToSuperview().inset(54)
            make.left.right.equalToSuperview().inset(16)
            make.height.equalTo(64)
        }

        bottomSheet.snp.makeConstraints { make in
            make.left.right.equalToSuperview()
            make.height.equalTo(180)
            make.bottom.equalToSuperview().inset(windowTabBarHeight)
        }
     
    }

    @objc private func centerToUser() {
        guard let coord = viewModel.getCurrentLocation() else { return }
        let target = YMKPoint(latitude: coord.latitude, longitude: coord.longitude)
        let pos = YMKCameraPosition(target: target, zoom: 14, azimuth: 0, tilt: 0)
        mapView.mapWindow.map.move(with: pos, animation: YMKAnimation(type: .smooth, duration: 0.7))
    }
    
    private func showBottomSheetAnimated() {
        guard bottomSheet.isHidden else { return }

           bottomSheet.transform = CGAffineTransform(translationX: 0, y: bottomSheet.frame.height)
           bottomSheet.isHidden = false

           locMeButtonBottomConstraint?.update(inset: bottomSheet.frame.height + windowTabBarHeight + 32)

           UIView.animate(withDuration: 0.3) {
               self.bottomSheet.transform = .identity
               self.view.layoutIfNeeded()
           }
    }

    private func hideBottomSheetAnimated() {
        guard !bottomSheet.isHidden else { return }

         UIView.animate(withDuration: 0.3, animations: {
             self.bottomSheet.transform = CGAffineTransform(translationX: 0, y: self.bottomSheet.frame.height)
             self.locMeButtonBottomConstraint?.update(inset: windowTabBarHeight + 32)
             self.view.layoutIfNeeded()
         }) { _ in
             self.bottomSheet.isHidden = true
             self.bottomSheet.transform = .identity
         }
    }

    func onCameraPositionChanged(with map: YMKMap, cameraPosition: YMKCameraPosition, cameraUpdateReason: YMKCameraUpdateReason, finished: Bool) {
        let coordinate = CLLocationCoordinate2D(
            latitude: cameraPosition.target.latitude,
            longitude: cameraPosition.target.longitude
        )
        selectedCoordinate = coordinate
        hideBottomSheetAnimated()
        scrollingEndedTimer?.invalidate()

        if finished {
            scrollingEndedTimer = Timer.scheduledTimer(withTimeInterval: 0.2, repeats: false) { [weak self] _ in
                guard let self = self else { return }
                self.viewModel.reverseGeocode(for: selectedCoordinate) { [weak self] title, subtitle in
                    self?.bottomSheet.update(title: title, subtitle: subtitle)
                    self?.showBottomSheetAnimated()
                }
            }
        }
    }
    
    
}

