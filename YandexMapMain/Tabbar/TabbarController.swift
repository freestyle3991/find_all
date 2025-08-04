//
//  TabbarView.swift
//  YandexMapLUDITO
//
//  Created by Muhammadjon Kuvandikov on 01/08/25.
//

import UIKit
import SnapKit


class TabbarController: UITabBarController, UITabBarControllerDelegate {
    private var lastSelectedIndex: Int?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        overrideUserInterfaceStyle = .light
        setupUITbabbar()
        self.viewControllers = self.getRegControllers()
        
        self.delegate = self
    }
    
    override func viewDidLayoutSubviews() {
        super.viewDidLayoutSubviews()
        
        let tabBarHeight: CGFloat = windowTabBarHeight
        let tabBarWidth: CGFloat = view.frame.width
        let tabBarX: CGFloat = 0
        let tabBarY: CGFloat = windowHeightA - tabBarHeight
        
        tabBar.frame = CGRect(x: tabBarX, y: tabBarY, width: tabBarWidth, height: tabBarHeight)
        tabBar.layer.cornerRadius = 8
        tabBar.layer.borderColor = UIColor(hex: "#CDC7C9").withAlphaComponent(0.4).cgColor
        tabBar.layer.borderWidth = 0.4
        tabBar.layer.masksToBounds = true
        tabBar.layer.maskedCorners = [.layerMinXMinYCorner, .layerMaxXMinYCorner]
        tabBar.barTintColor = UIColor(hex: "#FFFFFF")
    }
    
    func setupUITbabbar() {
        tabBar.backgroundColor = UIColor(hex: "#FFFFFF")
        tabBar.tintColor = UIColor(hex: "#000000")
        tabBar.unselectedItemTintColor = UIColor(hex: "#CDC7C9")
    }
    
    private func getRegControllers() -> [UIViewController] {
        var list = [UIViewController]()
        
        let saved = FavoritesViewController()
        let map = MapViewController()
        let profile = DevelopingViewController()
        
        list.append(initTabController(saved, title: "", image: UIImage(named: "saved_icon")!, image2: UIImage(named: "saved_icon"), tag: 0))
        
        list.append(initTabController(map, title: "", image: UIImage(named: "location_pin_small_icon")!, image2: UIImage(named: "location_pin_small_icon"), tag: 1))

        list.append(initTabController(profile, title: "", image: UIImage(named: "person_icon")!, image2: UIImage(named: "person_icon"), tag: 2))
        
        return list
    }
    
    private func initTabController(_ vc: UIViewController, title: String, image: UIImage, image2: UIImage? = nil, tag: Int = 0) -> UIViewController {
        vc.title = title
        vc.tabBarItem = UITabBarItem(title: title, image: image, selectedImage: image2 ?? image)
        vc.tabBarItem.tag = tag
        vc.tabBarItem.imageInsets = UIEdgeInsets(top: 0, left: 0, bottom: 0, right: 0)
        return vc
    }
    

}
