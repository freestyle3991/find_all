//
//  UITextField+Extension.swift
//  YandexMapLUDITO
//
//  Created by Muhammadjon Kuvandikov on 01/08/25.
//

import UIKit


extension UITextField {
    
    public var placeHolderColor: UIColor {
        set(color) {
            let text = self.placeholder ?? ""
            self.attributedPlaceholder =
            NSAttributedString(string: text, attributes: [NSAttributedString.Key.foregroundColor: color])
        }
        get {
            return self.textColor ?? .gray
        }
    }
    
    public var placeHolder: (String?, UIColor) {
        set(objc) {
            let text = objc.0 ?? ""
            self.attributedPlaceholder =
            NSAttributedString(string: text, attributes: [NSAttributedString.Key.foregroundColor: objc.1])
        }
        get {
            return (nil, self.textColor ?? .gray)
        }
    }
    
}
