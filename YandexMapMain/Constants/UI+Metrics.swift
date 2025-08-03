//
//  UI+Metrics.swift
//  YandexMapLUDITO
//
//  Created by Muhammadjon Kuvandikov on 31/07/25.
//


import UIKit
import YandexMapsMobile

public let windowHeightA = UIScreen.main.bounds.height
public let windowWidthA =  UIScreen.main.bounds.width
public var windowStatusBarHeightA: CGFloat {
    if let height = UIApplication.shared
        .connectedScenes
        .compactMap({ $0 as? UIWindowScene })
        .first?
        .statusBarManager?
        .statusBarFrame
        .height {
        return height
    }
    return 0
}
public let isXModelA: Bool = (windowWidthA >= 375 && windowHeightA >= 812)
public var windowTabBarHeight: CGFloat = isXModelA ? 86 : 74

public let boundingBox = YMKBoundingBox(
    southWest: YMKPoint(latitude: 37.033392, longitude: 55.912964),
    northEast: YMKPoint(latitude: 45.644006, longitude: 73.714221)
)

public let yandexApiKey = "8fc99099-9093-4dc6-85b1-838da8350c08"

