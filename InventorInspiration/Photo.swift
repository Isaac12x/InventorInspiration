//
//  Photo.swift
//  InventorInspiration
//
//  Created by Isaac Ramonet on 22/03/2017.
//  Copyright © 2017 com.IsaacRamonet. All rights reserved.
//

import Foundation
import UIKit
import CoreData


class Photo: NSObject {

    // MARK: Properties
    var image: UIImage?

    // MARK: Initializers
    
    init(image: UIImage) {
        self.image = image
    }

}
