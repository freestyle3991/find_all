//
//  SearchRecipientView.swift
//  YandexMapLUDITO
//
//  Created by Muhammadjon Kuvandikov on 01/08/25.
//


import UIKit
import SnapKit

class SearchMapView: UIView {
    
    private let baseView = UIView()
    private let imgView = UIImageView()
    private let textField = UITextField()
    private let closeBtn = UIButton()
    
    var onClear: ((Bool) -> Void)?
    var onText: ((String) -> Void)?
    
    override init(frame: CGRect) {
        super.init(frame: frame)
        setupViews()
        setupConstraints()
    }

    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }

    private func setupViews() {
        self.layer.cornerRadius = 16
        self.backgroundColor = UIColor(hex: "#FFFFFF")
        self.layer.borderColor = UIColor.lightGray.cgColor
        self.layer.borderWidth = 0.2
        self.layer.shadowColor = UIColor.lightGray.cgColor
        self.layer.shadowOpacity = 0.1
        self.layer.shadowOffset = .zero
        self.layer.shadowRadius = 8
        
        baseView.backgroundColor = .white
        baseView.layer.cornerRadius = 10
        baseView.layer.borderColor = UIColor.lightGray.cgColor
        baseView.layer.borderWidth = 0.6
        baseView.backgroundColor = UIColor(hex: "#EDEDED")
        
        imgView.image = UIImage(named: "search_icon")
        imgView.contentMode = .scaleAspectFit
 
        textField.font = UIFont.boldSystemFont(ofSize: 16)
        textField.textColor = UIColor(hex: "#000000")
        textField.placeHolderColor = .gray
        textField.keyboardType = .default
        textField.backgroundColor = .clear
        textField.attributedPlaceholder = NSAttributedString(
            string: "Поиск",
            attributes: [.foregroundColor: UIColor.gray]
        )
        textField.becomeFirstResponder()
        textField.addTarget(self, action: #selector(onTextChanged), for: .editingChanged)
        
        closeBtn.setImage(UIImage(named: "close_icon"), for: .normal)
        closeBtn.isHidden = true
        closeBtn.addTarget(self, action: #selector(onCloseBtn), for: .touchUpInside)
        
        addSubview(baseView)
        baseView.addSubview(imgView)
        baseView.addSubview(textField)
        baseView.addSubview(closeBtn)
    }

    private func setupConstraints() {
        baseView.snp.makeConstraints { make in
            make.top.equalToSuperview().offset(8)
            make.leading.trailing.equalToSuperview().inset(8)
            make.height.equalTo(48)
        }

        imgView.snp.makeConstraints { make in
            make.leading.equalToSuperview().offset(8)
            make.centerY.equalToSuperview()
            make.height.width.equalTo(24)
        }

        closeBtn.snp.makeConstraints { make in
            make.trailing.equalToSuperview().inset(12)
            make.centerY.equalToSuperview()
            make.height.width.equalTo(24)
        }

        textField.snp.makeConstraints { make in
            make.leading.equalTo(imgView.snp.trailing).offset(8)
            make.trailing.equalTo(closeBtn.snp.leading).offset(-12)
            make.top.bottom.equalToSuperview()
        }
    }

    @objc private func onCloseBtn() {
        textField.text = ""
        closeBtn.isHidden = true
        baseView.layer.borderColor = UIColor.lightGray.cgColor
        onClear?(true)
    }

    @objc private func onTextChanged() {
        let text = textField.text ?? ""
        closeBtn.isHidden = text.isEmpty
        baseView.layer.borderColor = text.isEmpty ? UIColor.lightGray.cgColor : UIColor.black.cgColor
        onText?(text)
    }

    func update(with text: String) {
        textField.text = text
    }
}

