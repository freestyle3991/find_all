//
//  FavoritesViewController.swift
//  YandexMapLUDITO
//
//  Created by Muhammadjon Kuvandikov on 01/08/25.
//


import UIKit
import SnapKit

final class FavoritesViewController: UIViewController {

    private var tableView = UITableView()
    private var favoriteList: [MapLocationModel] = []
    private var refreshcontroll = UIRefreshControl()

    override func viewDidLoad() {
        super.viewDidLoad()
        view.backgroundColor = UIColor(hex: "#F9F9F9")
        setupNavigationBarShadow()
        setupTableView()
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        let statusBarView = UIView(frame: UIApplication.shared.statusBarFrame)
        let statusBarColor = UIColor.white
        statusBarView.backgroundColor = statusBarColor
        self.view.addSubview(statusBarView)
        loadFavorites()
    }
    
    private func setupNavigationBarShadow() {
        let topView = UIView()
        topView.backgroundColor = UIColor(hex: "#FFFFFF")
        topView.layer.cornerRadius = 8
        topView.layer.maskedCorners = [.layerMinXMaxYCorner, .layerMaxXMaxYCorner]
        topView.layer.masksToBounds = false
        topView.layer.shadowColor = UIColor.black.cgColor
        topView.layer.shadowOpacity = 0.08
        topView.layer.shadowOffset = CGSize(width: 0, height: 3)
        topView.layer.shadowRadius = 4
        
        view.addSubview(topView)
        
        topView.snp.makeConstraints { make in
            make.top.equalToSuperview().offset(windowStatusBarHeightA)
            make.left.right.equalToSuperview()
            make.height.equalTo(52)
        }

        let label = UILabel()
        label.font = UIFont.boldSystemFont(ofSize: 24)
        label.textColor = .black
        label.textAlignment = .center
        label.numberOfLines = 1
        label.text = "Мои адреса"

        topView.addSubview(label)

        label.snp.makeConstraints { make in
            make.edges.equalToSuperview().inset(12)
        }
    }

    private func setupTableView() {
        tableView = UITableView(frame: .zero, style: .plain)
        tableView.separatorStyle = .none
        tableView.backgroundColor = .clear
        tableView.register(FavoriteLocationCell.self, forCellReuseIdentifier: "FavoriteLocationCell")
        tableView.register(EmptyFavoritesCell.self, forCellReuseIdentifier: "EmptyFavoritesCell")
        tableView.dataSource = self
        tableView.delegate = self
        tableView.refreshControl = self.refreshcontroll
        tableView.contentInset.top = 24
        refreshcontroll.addTarget(self, action: #selector(refreshVal), for: .valueChanged)

        view.addSubview(tableView)
        
        tableView.snp.makeConstraints { make in
            make.top.equalToSuperview().offset(windowStatusBarHeightA + 52)
            make.left.right.bottom.equalToSuperview()
        }
    }

    private func loadFavorites() {
        favoriteList = FavoritesStorage.getArrayFavorit()
        tableView.reloadData()
    }
    
    @objc func refreshVal() {
        refreshcontroll.beginRefreshing()
        loadFavorites()
        refreshcontroll.endRefreshing()
    }
}

extension FavoritesViewController: UITableViewDataSource {
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return favoriteList.isEmpty ? 1 : favoriteList.count

    }

    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        if favoriteList.isEmpty {
            let cell = tableView.dequeueReusableCell(withIdentifier: "EmptyFavoritesCell", for: indexPath) as! EmptyFavoritesCell
            cell.backgroundColor = .clear
            cell.selectionStyle = .none
            return cell
        } else {
            guard let cell = tableView.dequeueReusableCell(withIdentifier: "FavoriteLocationCell", for: indexPath) as? FavoriteLocationCell else {
                return UITableViewCell()
            }
            let model = favoriteList[indexPath.row]
            cell.configure(with: model)
            cell.backgroundColor = .clear
            cell.selectionStyle = .none
            return cell
        }
    }

}

extension FavoritesViewController: UITableViewDelegate {
    func tableView(_ tableView: UITableView, trailingSwipeActionsConfigurationForRowAt indexPath: IndexPath) -> UISwipeActionsConfiguration? {
        guard !favoriteList.isEmpty else { return nil }

        let model = favoriteList[indexPath.row]

        let deleteAction = UIContextualAction(style: .destructive, title: "Удалить") { _, _, completion in
            FavoritesStorage.remove(item: model)
            self.favoriteList.remove(at: indexPath.row)

            if self.favoriteList.isEmpty {
                tableView.reloadData()
            } else {
                tableView.deleteRows(at: [indexPath], with: .automatic)
            }
            completion(true)
        }
        deleteAction.backgroundColor = .systemRed
        let configuration = UISwipeActionsConfiguration(actions: [deleteAction])
        configuration.performsFirstActionWithFullSwipe = true
        return configuration
    }
}
