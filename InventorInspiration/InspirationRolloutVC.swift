//
//  InspirationRolloutVC.swift
//  InventorInspiration
//
//  Created by Isaac Albets Ramonet on 05/04/2017.
//  Copyright © 2017 com.IsaacRamonet. All rights reserved.
//

import UIKit
//import ImageSlideshow


class InspirationRolloutVC: UIViewController {
    
    // Configure the view
    open override var supportedInterfaceOrientations: UIInterfaceOrientationMask {
        
        // the orientation object -- this should be an observed object
        var deviceOrientation = UIInterfaceOrientation(rawValue: 1)
        
        // If device is on portrait mode
        if UIInterfaceOrientationIsPortrait(deviceOrientation!){
            return .portrait
        
        // else if device is in landscape
        } else if UIInterfaceOrientationIsLandscape(deviceOrientation!) {
            return .landscape
        
        // else return error
        } else {
            // error
        }
        
    }
    
    @IBOutlet var slideshow: ImageSlideshow!
    
    //let localSource = [ImageSource(imageString: "img1")!, ImageSource(imageString: "img2")!, ImageSource(imageString: "img3")!, ImageSource(imageString: "img4")!]
    let afNetworkingSource = [AFURLSource(urlString: "https://images.unsplash.com/photo-1432679963831-2dab49187847?w=1080")!, AFURLSource(urlString: "https://images.unsplash.com/photo-1447746249824-4be4e1b76d66?w=1080")!, AFURLSource(urlString: "https://images.unsplash.com/photo-1463595373836-6e0b0a8ee322?w=1080")!]
    let alamofireSource = [AlamofireSource(urlString: "https://images.unsplash.com/photo-1432679963831-2dab49187847?w=1080")!, AlamofireSource(urlString: "https://images.unsplash.com/photo-1447746249824-4be4e1b76d66?w=1080")!, AlamofireSource(urlString: "https://images.unsplash.com/photo-1463595373836-6e0b0a8ee322?w=1080")!]
    let sdWebImageSource = [SDWebImageSource(urlString: "https://images.unsplash.com/photo-1432679963831-2dab49187847?w=1080")!, SDWebImageSource(urlString: "https://images.unsplash.com/photo-1447746249824-4be4e1b76d66?w=1080")!, SDWebImageSource(urlString: "https://images.unsplash.com/photo-1463595373836-6e0b0a8ee322?w=1080")!]
    let kingfisherSource = [KingfisherSource(urlString: "https://images.unsplash.com/photo-1432679963831-2dab49187847?w=1080")!, KingfisherSource(urlString: "https://images.unsplash.com/photo-1447746249824-4be4e1b76d66?w=1080")!, KingfisherSource(urlString: "https://images.unsplash.com/photo-1463595373836-6e0b0a8ee322?w=1080")!]
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        slideshow.backgroundColor = UIColor.white
        slideshow.slideshowInterval = 0.20
        //mslideshow.pageControlPosition = PageControlPosition.underScrollView
        slideshow.pageControl.currentPageIndicatorTintColor = UIColor.lightGray
        slideshow.pageControl.pageIndicatorTintColor = UIColor.black
        slideshow.contentScaleMode = UIViewContentMode.scaleAspectFill
        slideshow.currentPageChanged = { page in
            print("current page:", page)
        }
        
        // try out other sources such as `afNetworkingSource`, `alamofireSource` or `sdWebImageSource` or `kingfisherSource`
        slideshow.setImageInputs(alamofireSource)
        
        let recognizer = UITapGestureRecognizer(target: self, action: #selector(InspirationRolloutVC.didTap))
        slideshow.addGestureRecognizer(recognizer)
    }
    
    func didTap() {
        //dismiss slideshow
        slideshow.presentFullScreenController(from: self)
    }
    
    func didHoldPress() {
        //present slideshow
    }
}
