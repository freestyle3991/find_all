//
//  BottomSheetView.swift
//  YandexMapLUDITO
//
//  Created by Muhammadjon Kuvandikov on 01/08/25.
//

import UIKit
import SnapKit

final class BottomSheetView: UIView {

    var onAction: ((Int) -> Void)?

    private let titleLabel = UILabel()
    private let subtitleLabel = UILabel()
    private let closeButton = UIButton()
    private let starStackView = UIStackView()
    private let feedbackLabel = UILabel()
    private let favoriteButton = UIButton()

    override init(frame: CGRect) {
        super.init(frame: frame)
        setupUI()
    }

    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }

    private func setupUI() {
        self.backgroundColor = UIColor(hex: "#F9F9F9")
        self.layer.cornerRadius = 8
        self.layer.maskedCorners = [.layerMinXMinYCorner, .layerMaxXMinYCorner]
        self.layer.shadowColor = UIColor.black.cgColor
        self.layer.shadowOpacity = 0.2
        self.layer.shadowOffset = CGSize(width: 0, height: 4)
        self.layer.shadowRadius = 6
        self.layer.masksToBounds = false

        titleLabel.font = .boldSystemFont(ofSize: 20)
        titleLabel.textColor = .black

        subtitleLabel.font = .systemFont(ofSize: 16)
        subtitleLabel.textColor = .gray
        subtitleLabel.numberOfLines = 2

        closeButton.setImage(UIImage(named: "close_icon"), for: .normal)
        closeButton.tintColor = .lightGray
        closeButton.addTarget(self, action: #selector(closeTapped), for: .touchUpInside)

        starStackView.axis = .horizontal
        starStackView.spacing = 4
        starStackView.alignment = .center
        for _ in 0..<5 {
            let star = UIImageView(image: UIImage(named: "star_green_unselected"))
//            star.tintColor = UIColor.green
            star.contentMode = .scaleAspectFit
            star.snp.makeConstraints { make in
                make.width.height.equalTo(16)
            }
            starStackView.addArrangedSubview(star)
        }

        feedbackLabel.font = .systemFont(ofSize: 13)
        feedbackLabel.textColor = .lightGray

        favoriteButton.setTitle("Добавить в избранное", for: .normal)
        favoriteButton.setTitleColor(.white, for: .normal)
        favoriteButton.backgroundColor = UIColor(hex: "#5BC250")
        favoriteButton.titleLabel?.font = .boldSystemFont(ofSize: 16)
        favoriteButton.layer.cornerRadius = 22
        favoriteButton.addTarget(self, action: #selector(favoriteTapped), for: .touchUpInside)

        // Add subviews
        addSubview(titleLabel)
        addSubview(subtitleLabel)
        addSubview(closeButton)
        addSubview(starStackView)
        addSubview(feedbackLabel)
        addSubview(favoriteButton)

        closeButton.snp.makeConstraints { make in
            make.top.equalToSuperview().offset(20)
            make.trailing.equalToSuperview().inset(16)
            make.width.height.equalTo(24)
        }

        titleLabel.snp.makeConstraints { make in
            make.top.equalToSuperview().offset(12)
            make.leading.equalToSuperview().inset(16)
            make.trailing.equalTo(closeButton.snp.leading).offset(-6)
        }

        subtitleLabel.snp.makeConstraints { make in
            make.top.equalTo(titleLabel.snp.bottom).offset(4)
            make.leading.equalTo(titleLabel.snp.leading)
            make.trailing.equalToSuperview().inset(16)
        }

        starStackView.snp.makeConstraints { make in
            make.top.equalTo(subtitleLabel.snp.bottom).offset(12)
            make.leading.equalTo(subtitleLabel.snp.leading)
            make.height.equalTo(16)
        }

        feedbackLabel.snp.makeConstraints { make in
            make.centerY.equalTo(starStackView)
            make.leading.equalTo(starStackView.snp.trailing).offset(8)
        }

        favoriteButton.snp.makeConstraints { make in
            make.top.equalTo(starStackView.snp.bottom).offset(14)
            make.leading.equalToSuperview().offset(16)
            make.width.equalToSuperview().multipliedBy(0.6)
            make.height.equalTo(42)
            make.bottom.equalToSuperview().inset(24)
        }
    }
    
    func update(title: String, subtitle: String) {
        titleLabel.text = title
        subtitleLabel.text = subtitle

        let randomStarCount = Int.random(in: 1...5)
        for (index, view) in starStackView.arrangedSubviews.enumerated() {
            if let star = view as? UIImageView {
                if index < randomStarCount {
                    star.image = UIImage(named: "star_green")
                } else {
                    star.image = UIImage(named: "star_green_unselected")
                }
            }
        }
        let feedbackNumber = Int.random(in: 5...500)
        feedbackLabel.text = "\(feedbackNumber) оценок"
    }
    
    func getTitle() -> String {
        return titleLabel.text ?? ""
    }

    func getSubtitle() -> String {
        return subtitleLabel.text ?? ""
    }

    @objc private func closeTapped() {
        onAction?(0)
    }

    @objc private func favoriteTapped() {
        onAction?(1)
    }
    
    
}

