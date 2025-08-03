//
//  DevelopingViewController.swift
//  YandexMapLUDITO
//
//  Created by Muhammadjon Kuvandikov on 01/08/25.
//

import UIKit
import SnapKit

class DevelopingViewController: UIViewController {
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        self.view.backgroundColor = .white
        self.setupUI()
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
    }
    
    override func viewWillDisappear(_ animated: Bool) {
        super.viewWillDisappear(animated)
    }
    

    func setupUI() {
        let label = UILabel()
        label.text = "Страница в разработке"
        label.font = .boldSystemFont(ofSize: 20)
        label.backgroundColor = .clear
        label.textColor = .black
        label.textAlignment = .center
        label.numberOfLines = 0

        self.view.addSubview(label)
        
        label.snp.makeConstraints { make in
            make.center.equalToSuperview()
            make.left.right.equalToSuperview()
        }
    }

}
