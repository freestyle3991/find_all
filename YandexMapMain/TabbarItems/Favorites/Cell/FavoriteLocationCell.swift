//
//  FavoriteLocationCell.swift
//  YandexMapLUDITO
//
//  Created by Muhammadjon Kuvandikov on 01/08/25.
//

import UIKit
import SnapKit

final class FavoriteLocationCell: UITableViewCell {

    private let container = UIView()
    private let titleLabel = UILabel()
    private let subtitleLabel = UILabel()
    private let iconImageView = UIImageView()

    override init(style: UITableViewCell.CellStyle, reuseIdentifier: String?) {
        super.init(style: style, reuseIdentifier: reuseIdentifier)
        setupViews()
        setupConstraints()
    }

    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }

    func configure(with model: MapLocationModel) {
        titleLabel.text = model.title
        subtitleLabel.text = model.subtitle
    }

    private func setupViews() {
        backgroundColor = .clear
        contentView.backgroundColor = .clear

        container.backgroundColor = .white
        container.layer.cornerRadius = 12
        container.layer.shadowColor = UIColor.black.cgColor
        container.layer.shadowOpacity = 0.05
        container.layer.shadowRadius = 4
        container.layer.shadowOffset = CGSize(width: 0, height: 2)

        titleLabel.font = .boldSystemFont(ofSize: 16)
        titleLabel.textColor = .black

        subtitleLabel.font = .boldSystemFont(ofSize: 14)
        subtitleLabel.textColor = .gray
        subtitleLabel.numberOfLines = 2

        iconImageView.image = UIImage(named: "location_pin_favorite_icon")
        iconImageView.contentMode = .scaleAspectFit

        contentView.addSubview(container)
        container.addSubview(titleLabel)
        container.addSubview(subtitleLabel)
        container.addSubview(iconImageView)
    }

    private func setupConstraints() {
        container.snp.makeConstraints { make in
            make.top.bottom.equalToSuperview().inset(6)
            make.left.right.equalToSuperview().inset(16)
        }

        iconImageView.snp.makeConstraints { make in
            make.right.equalToSuperview().inset(12)
            make.centerY.equalToSuperview()
            make.size.equalTo(32)
        }

        titleLabel.snp.makeConstraints { make in
            make.top.equalToSuperview().offset(12)
            make.left.equalToSuperview().offset(12)
            make.right.equalTo(iconImageView.snp.left).offset(-8)
        }

        subtitleLabel.snp.makeConstraints { make in
            make.top.equalTo(titleLabel.snp.bottom).offset(4)
            make.left.equalTo(titleLabel)
            make.right.equalTo(titleLabel)
            make.bottom.equalToSuperview().inset(12)
        }
    }
}

