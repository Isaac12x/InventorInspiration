//
//  DetailViewController.swift
//  InventorInspiration
//
//  Created by Isaac Ramonet on 22/03/2017.
//  Copyright © 2017 com.IsaacRamonet. All rights reserved.
//

import UIKit
import Redbeard

class DetailViewController: UIViewController {

    // MARK: Properties
    @IBOutlet weak var imageRoller: UIImageView!
    @IBOutlet weak var sliderTitleLabel:UILabel!
    @IBOutlet weak var speedSlider: UISlider!
    @IBOutlet weak var speedSliderLabel: UILabel!
    @IBOutlet weak var switchLabel: UILabel!
    @IBOutlet weak var randomSwitcher: UISwitch!
    // @IBOutlet weak var shouldDisplayNotes: UILabel!
    // @IBOutlet weak var shouldDisplayNotes: UISwitch!
    // gesture recognizer plays the movie
    @IBOutlet var tapGestureRecognizer: UITapGestureRecognizer!
    
    var workspaceImageCollection: [Photo]?
    
    func configureView() {
        // Update the user interface for the detail item.
        //if let detail = self.detailItem {
        //    if let label = self.detailDescriptionLabel {
        //       label.text = detail.description
        //   }
        //}
    }

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        
        // configure the labels
        sliderTitleLabel.text = ""
        speedSliderLabel.text = "0"
        switchLabel.text = "Randomize?"
        
        //configure the navigation bar
        let backButton = navigationController?.navigationItem.backBarButtonItem
        navigationItem.leftBarButtonItem = backButton
        
        // TODO: Change the selector
        tapGestureRecognizer.addTarget(self, action: #selector(DetailViewController.configureView))
        self.configureView()
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    var detailItem: NSDate? {
        didSet {
            // Update the view.
            self.configureView()
        }
    }
    
    var firstImageData: UIImageView? {
        didSet {
            // update the view
            self.configureView()
        }
    }

    // for now default to endless rotation
    func playTheInspirationalMovieWithOptions(rate: CGFloat, pitch: CGFloat, randomized: Bool = false) {
        // get the data first
        
        // check if user wants it randomized
        if randomized != true {
        
        } else {
            // if true, randomize the array indexes
            let randomizedData = workspaceImageCollection
            randomizedData?.shuffled()
            
            // pass the data to the presenter
        }
    }
    
}


extension MutableCollection where Indices.Iterator.Element == Index {
    /// Shuffles the contents of this collection.
    mutating func shuffle() {
        let c = count
        guard c > 1 else { return }
        
        for (firstUnshuffled , unshuffledCount) in zip(indices, stride(from: c, to: 1, by: -1)) {
            let d: IndexDistance = numericCast(arc4random_uniform(numericCast(unshuffledCount)))
            guard d != 0 else { continue }
            let i = index(firstUnshuffled, offsetBy: d)
            swap(&self[firstUnshuffled], &self[i])
        }
    }
}

extension Sequence {
    /// Returns an array with the contents of this sequence, shuffled.
    func shuffled() -> [Iterator.Element] {
        var result = Array(self)
        result.shuffle()
        return result
    }
}

