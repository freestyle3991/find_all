//
//  MapLocationModel.swift
//  YandexMapLUDITO
//
//  Created by Muhammadjon Kuvandikov on 01/08/25.
//

import Foundation
import CoreLocation

struct MapLocationModel: Codable, Equatable {
    var title: String
    var subtitle: String
    var coordinate: CLLocationCoordinate2D
    var id: Int

    static func == (lhs: MapLocationModel, rhs: MapLocationModel) -> Bool {
        return lhs.id == rhs.id
    }
}

extension CLLocationCoordinate2D: Codable {
    public func encode(to encoder: Encoder) throws {
        var container = encoder.container(keyedBy: CodingKeys.self)
        try container.encode(latitude, forKey: .latitude)
        try container.encode(longitude, forKey: .longitude)
    }

    public init(from decoder: Decoder) throws {
        let container = try decoder.container(keyedBy: CodingKeys.self)
        let latitude = try container.decode(CLLocationDegrees.self, forKey: .latitude)
        let longitude = try container.decode(CLLocationDegrees.self, forKey: .longitude)
        self.init(latitude: latitude, longitude: longitude)
    }

    enum CodingKeys: String, CodingKey {
        case latitude
        case longitude
    }
}

