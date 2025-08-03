//
//  EmptyFavoritesCell.swift
//  YandexMapLUDITO
//
//  Created by Muhammadjon Kuvandikov on 02/08/25.
//

import UIKit
import SnapKit

final class EmptyFavoritesCell: UITableViewCell {
    
    private let messageLabel: UILabel = {
        let label = UILabel()
        label.text = "У вас нет сохранённых адресов"
        label.textColor = UIColor(hex: "#7A7A7A")
        label.font = .systemFont(ofSize: 18, weight: .medium)
        label.textAlignment = .center
        label.numberOfLines = 0
        return label
    }()
    
    override init(style: UITableViewCell.CellStyle, reuseIdentifier: String?) {
        super.init(style: style, reuseIdentifier: reuseIdentifier)
        backgroundColor = .clear
        contentView.addSubview(messageLabel)
        messageLabel.snp.makeConstraints { make in
            make.center.equalToSuperview()
            make.left.right.equalToSuperview().inset(32)
            make.height.greaterThanOrEqualTo(100)
        }
        selectionStyle = .none
    }

    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
}
