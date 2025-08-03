//
//  MapViewModel.swift
//  YandexMapLUDITO
//
//  Created by Muhammadjon Kuvandikov on 01/08/25.
//

import Foundation
import CoreLocation
import YandexMapsMobile

final class MapViewModel: NSObject, CLLocationManagerDelegate {
    
    var currentLocation: CLLocationCoordinate2D?
    var onLocationAvailable: ((CLLocationCoordinate2D) -> Void)?
    
    private let locationManager = CLLocationManager()
    private let openCageService = OpenCageService()
    private let searchManager = YMKSearch.sharedInstance().createSearchManager(with: .combined)
    private var didCenterOnce = false

    
    override init() {
        super.init()
        locationManager.delegate = self
    }

    func requestLocationAccess() {
        if CLLocationManager.authorizationStatus() == .notDetermined {
            locationManager.requestWhenInUseAuthorization()
        } else {
            locationManager.startUpdatingLocation()
        }
    }

    func getCurrentLocation() -> CLLocationCoordinate2D? {
        return locationManager.location?.coordinate
    }
    
    func reverseGeocode(for coordinate: CLLocationCoordinate2D, completion: @escaping (String, String) -> Void) {
        openCageService.getAddress(for: coordinate) { title, subtitle in
             completion(title, subtitle)
         }
    }

    func locationManager(_ manager: CLLocationManager, didUpdateLocations locations: [CLLocation]) {
           guard let latest = locations.last else { return }
        currentLocation = latest.coordinate

          if !didCenterOnce {
              didCenterOnce = true
              onLocationAvailable?(latest.coordinate)
          }
       }

}
