//
//  SearchView.swift
//  YandexMapLUDITO
//
//  Created by Muhammadjon Kuvandikov on 01/08/25.
//

import UIKit
import SnapKit

final class SearchView: UIView {
    
    var onActionPress: (() -> Void)?
    
    private let baseView = UIView()
    private let searchIconImageView = UIImageView()
    private let searchLabel = UILabel()
    private let actionFullButton = UIButton()
    
    override init(frame: CGRect) {
        super.init(frame: frame)
        setupUI()
    }
    
    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    private func setupUI() {
        self.backgroundColor = UIColor(hex: "#FFFFFF")
        self.layer.cornerRadius = 16
        self.layer.shadowColor = UIColor.black.cgColor
        self.layer.shadowOpacity = 0.2
        self.layer.shadowOffset = CGSize(width: 0, height: 4)
        self.layer.shadowRadius = 6
        self.layer.masksToBounds = false
        
        baseView.backgroundColor = UIColor(hex: "#E0E0E0")
        baseView.layer.cornerRadius = 10
        
        self.addSubview(baseView)
        baseView.addSubview(searchIconImageView)
        baseView.addSubview(searchLabel)
        self.addSubview(actionFullButton)
        
        searchLabel.text = "Поиск"
        searchLabel.font = .boldSystemFont(ofSize: 16)
        searchLabel.textColor = .black
        searchLabel.numberOfLines = 1
        searchLabel.textAlignment = .left
        
        searchIconImageView.backgroundColor = .clear
        searchIconImageView.image = UIImage(named: "search_icon")
        searchIconImageView.contentMode = .scaleAspectFill
        
        actionFullButton.addTarget(self, action: #selector(onAction(_ :)), for: .touchUpInside)
        
        baseView.snp.makeConstraints { make in
            make.edges.equalToSuperview().inset(8)
        }
        
        searchIconImageView.snp.makeConstraints { make in
            make.centerY.equalToSuperview()
            make.leading.equalToSuperview().inset(12)
            make.width.height.equalTo(24)
        }
        
        searchLabel.snp.makeConstraints { make in
            make.centerY.equalToSuperview()
            make.leading.equalTo(searchIconImageView.snp.trailing).offset(8)
            make.trailing.equalToSuperview().inset(20)
        }
        
        actionFullButton.snp.makeConstraints { make in
            make.edges.equalToSuperview().inset(12)
        }
    }
    
    @objc func onAction(_ sender: UIButton){
        self.onActionPress?()
    }
}
