//
//  Constants.swift
//  InventorInspiration
//
//  Created by Isaac Ramonet on 24/03/2017.
//  Copyright © 2017 com.IsaacRamonet. All rights reserved.
//

import UIKit


let scale1x = UITraitCollection(displayScale: 1.0)
let scale2x = UITraitCollection(displayScale: 2.0)
let scale3x = UITraitCollection(displayScale: 3.0)


extension UIImageView {
    
    func downloadedFrom(url: URL, contentMode mode: UIViewContentMode = .scaleAspectFit) {
        contentMode = mode
        let task = URLSession.shared.dataTask(with: url) { (data, response, error) in
            guard
                let httpURLResponse = response as? HTTPURLResponse, httpURLResponse.statusCode == 200,
                let mimeType = response?.mimeType, mimeType.hasPrefix("image"),
                let data = data, error == nil,
                let image = UIImage(data: data)
                else { return }
            DispatchQueue.main.async() { () -> Void in
                self.image = image
            }
        }
        
        task.resume()
    }
    
    func downloadedFrom(link: String, contentMode mode: UIViewContentMode = .scaleAspectFit) {
        guard let url = URL(string: link) else { return }
        downloadedFrom(url: url, contentMode: mode)
    }
}




// Reversed appearing
public extension UINavigationController {
    
    func pushViewControllerFromTop(viewController vc: UIViewController) {
        vc.view.alpha = 0
        self.present(vc, animated: false) { () -> Void in
            vc.view.frame = CGRect(x: 0, y: -vc.view.frame.height, width: vc.view.frame.width, height: vc.view.frame.height)
            vc.view.alpha = 1.0
            UIView.animate(withDuration: 1, animations: { () -> Void in
                vc.view.frame = CGRect(x: 0, y: 0, width: vc.view.frame.width, height: vc.view.frame.height)
            },
                           completion: nil)
        }
    }
    
    func dismissViewControllerToTop() {
        if let vc = self.presentedViewController {
            UIView.animate(withDuration: 1, animations: { () -> Void in
                vc.view.frame = CGRect(x: 0, y: -vc.view.frame.height, width: vc.view.frame.width, height: vc.view.frame.height)
            }, completion: { (complete) -> Void in
                if complete == true {
                    self.dismiss(animated: false, completion: nil)
                }
            })
        }
    }
}
