//
//  InspireImageCollection.swift
//  InventorInspiration
//
//  Created by Isaac Ramonet on 22/03/2017.
//  Copyright © 2017 com.IsaacRamonet. All rights reserved.
//

import Foundation

class InspireImageCollection: NSObject {

    var title: String?
    var inspireCollection: [Photo]?
    
    init(title: String, inspireCollection: [Photo]) {
        self.title = title
        self.inspireCollection = inspireCollection
    }
//    
//    class func sharedInstance() -> InspireImageCollection {
//        
//        struct Singleton {
//            static var sharedInstance = InspireImageCollection()
//        }
//        
//        return Singleton.sharedInstance
//    }

}
