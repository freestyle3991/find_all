//
//  MapSearchSuggestCell.swift
//  YandexMapLUDITO
//
//  Created by Muhammadjon Kuvandikov on 01/08/25.
//


import UIKit
import SnapKit
import YandexMapsMobile

class MapSearchSuggestCell: UITableViewCell {
    
    var onAction: ((YMKSuggestItem?) -> Void)?
    private var model: YMKSuggestItem?

    var isFirst: Bool = false {
        didSet {
            topDividerView.isHidden = !isFirst
        }
    }

    private let iconImageView: UIImageView = {
        let imageView = UIImageView()
        imageView.image = UIImage(named: "location_pin_small_icon")?.withRenderingMode(.alwaysTemplate)
        imageView.tintColor = UIColor(hex: "#939393")
        imageView.contentMode = .scaleAspectFit
        return imageView
    }()
    
    private let titleLabel: UILabel = {
        let label = UILabel()
        label.font = .boldSystemFont(ofSize: 16)
        label.textColor = UIColor(hex: "#000000")
        label.numberOfLines = 1
        label.lineBreakMode = .byTruncatingTail
        return label
    }()
    
    private let distanceLabel: UILabel = {
        let label = UILabel()
        label.font = .boldSystemFont(ofSize: 14)
        label.textColor = UIColor(hex: "#000000")
        label.textAlignment = .right
        return label
    }()
    
    private let subtitleLabel: UILabel = {
        let label = UILabel()
        label.font = .systemFont(ofSize: 13)
        label.textColor = .gray
        label.numberOfLines = 2
        return label
    }()
    
    private let topDividerView: UIView = {
        let view = UIView()
        view.backgroundColor = UIColor(hex: "#E5E5E5")
        view.isHidden = true
        return view
    }()
    
    private let bottomDividerView: UIView = {
        let view = UIView()
        view.backgroundColor = UIColor(hex: "#E5E5E5")
        return view
    }()
    
    private let fullButton = UIButton()

    override init(style: UITableViewCell.CellStyle, reuseIdentifier: String?) {
        super.init(style: style, reuseIdentifier: reuseIdentifier)
        setupViews()
        setupConstraints()
        fullButton.addTarget(self, action: #selector(didTap), for: .touchUpInside)
    }

    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }

    func configure(with model: YMKSuggestItem, distance: String) {
        self.model = model
        titleLabel.text = model.displayText
        subtitleLabel.text = model.subtitle?.text ?? ""
        distanceLabel.text = distance
    }

    private func setupViews() {
        contentView.backgroundColor = UIColor(hex: "#F9F9F9")
        contentView.addSubview(iconImageView)
        contentView.addSubview(titleLabel)
        contentView.addSubview(distanceLabel)
        contentView.addSubview(subtitleLabel)
        contentView.addSubview(topDividerView)
        contentView.addSubview(bottomDividerView)
        contentView.addSubview(fullButton)
        
        distanceLabel.setContentHuggingPriority(.required, for: .horizontal)
        distanceLabel.setContentCompressionResistancePriority(.required, for: .horizontal)

    }

    private func setupConstraints() {
        topDividerView.snp.makeConstraints { make in
            make.top.equalToSuperview()
            make.left.equalToSuperview()
            make.right.equalToSuperview()
            make.height.equalTo(1)
        }

        iconImageView.snp.makeConstraints { make in
            make.left.equalToSuperview().offset(16)
            make.centerY.equalToSuperview()
            make.width.height.equalTo(32)
        }
        
        distanceLabel.snp.makeConstraints { make in
            make.top.equalToSuperview().offset(12)
            make.right.equalToSuperview().inset(16)
        }

        titleLabel.snp.makeConstraints { make in
            make.top.equalToSuperview().offset(12)
            make.left.equalTo(iconImageView.snp.right).offset(12)
            make.right.lessThanOrEqualTo(distanceLabel.snp.left).offset(-4)
        }

        subtitleLabel.snp.makeConstraints { make in
            make.top.equalTo(titleLabel.snp.bottom).offset(2)
            make.left.equalTo(titleLabel.snp.left)
            make.right.equalToSuperview().inset(12)
            make.bottom.equalToSuperview().inset(10)
        }

        bottomDividerView.snp.makeConstraints { make in
            make.left.equalToSuperview()
            make.right.equalToSuperview()
            make.bottom.equalToSuperview()
            make.height.equalTo(1)
        }

        fullButton.snp.makeConstraints { make in
            make.edges.equalToSuperview()
        }
    }

    @objc private func didTap() {
        onAction?(model)
    }
}
