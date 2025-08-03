//
//  OpenCageService.swift
//  YandexMapLUDITO
//
//  Created by Muhammadjon Kuvandikov on 01/08/25.
//

import Foundation
import CoreLocation

final class OpenCageService {
    private let apiKey = "eda4d67d308e4dcda265a8cc98551968"

    func getAddress(for coordinate: CLLocationCoordinate2D, completion: @escaping (String, String) -> Void) {
        let urlString = "https://api.opencagedata.com/geocode/v1/json?q=\(coordinate.latitude),\(coordinate.longitude)&key=\(apiKey)&language=ru&pretty=1"

        guard let url = URL(string: urlString) else {
            completion("Noto‘g‘ri URL", "")
            return
        }

        let request = URLRequest(url: url)
        let task = URLSession.shared.dataTask(with: request) { data, _, error in
            guard let data = data, error == nil else {
                DispatchQueue.main.async {
                    completion("Tarmoq xatosi", "")
                }
                return
            }

            do {
                if let json = try JSONSerialization.jsonObject(with: data) as? [String: Any],
                   let results = json["results"] as? [[String: Any]],
                   let first = results.first {

                    let components = first["components"] as? [String: Any]
                    let formatted = first["formatted"] as? String ?? "Manzil mavjud emas"

                    
                    let title = components?["building"] as? String ??
                                components?["attraction"] as? String ??
                                components?["road"] as? String ??
                                components?["neighbourhood"] as? String ??
                                components?["suburb"] as? String ??
                                "Nomaʼlum joy"

                   
                    let subtitle = formatted
                        .replacingOccurrences(of: "\\b\\d{5,6}\\b", with: "", options: .regularExpression) //remove postal code
                        .components(separatedBy: ",")
                        .dropLast() //remove country
                        .map { $0.trimmingCharacters(in: .whitespaces) }
                        .joined(separator: ", ")

                    DispatchQueue.main.async {
                        completion(title, subtitle)
                    }

                } else {
                    DispatchQueue.main.async {
                        completion("Topilmadi", "")
                    }
                }
            } catch {
                DispatchQueue.main.async {
                    completion("Dekodlash xatosi", "")
                }
            }
        }

        task.resume()
    }

}

