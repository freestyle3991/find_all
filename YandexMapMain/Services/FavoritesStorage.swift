//
//  FavoritesStorage.swift
//  YandexMapLUDITO
//
//  Created by Muhammadjon Kuvandikov on 01/08/25.
//
import UIKit

final class FavoritesStorage {
    private static let key = "favorite_addresses"

    static func saveArrayFavorit(model: [MapLocationModel]) {
        if let data = try? JSONEncoder().encode(model) {
            UserDefaults.standard.set(data, forKey: key)
        }
    }

    static func getArrayFavorit() -> [MapLocationModel] {
        guard let data = UserDefaults.standard.data(forKey: key),
              let decoded = try? JSONDecoder().decode([MapLocationModel].self, from: data) else {
            return []
        }
        return decoded
    }

    static func add(item: MapLocationModel) {
        var current = getArrayFavorit()
        if !current.contains(where: { $0.id == item.id }) {
            current.append(item)
            saveArrayFavorit(model: current)
        }
    }

    static func remove(item: MapLocationModel) {
        var current = getArrayFavorit()
        current.removeAll { $0.id == item.id }
        saveArrayFavorit(model: current)
    }
}

