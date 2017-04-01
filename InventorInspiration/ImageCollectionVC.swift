//
//  ImageCollectionVC.swift
//  InventorInspiration
//
//  Created by Isaac Ramonet on 22/03/2017.
//  Copyright © 2017 com.IsaacRamonet. All rights reserved.
//

import UIKit

class ImageCollectionVC: UIViewController {
    
    // MARK: Properties
    @IBOutlet weak var collectionView: UICollectionView!
    @IBOutlet weak var toolbar: UIToolbar!
    @IBOutlet weak var layout: UICollectionViewFlowLayout!
    
    
    var photos = [Photo]()
    var inpirationStore: InspireImageCollection?
    
    var selectedIndexes = [NSIndexPath]()
    let noImagesLabel = UILabel(frame: CGRect(x: 0, y: 0, width: 330, height: 50))


    
    // MARK: View lifecycle
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        
        if photos.count == 0 {
            // present a bottom bar button
        } else {
            // present the bar as the starting point
        }
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        // Set a label for when there is nothing to sync
        noImagesLabel.center = CGPoint(x: view.frame.width/2, y: view.frame.height/2)
        noImagesLabel.text = "Nothing to sync yet"
        noImagesLabel.tintColor = UIColor.darkGray
        noImagesLabel.font = UIFont.boldSystemFont(ofSize: 34)
        noImagesLabel.alpha = 0.5
        noImagesLabel.shadowColor = UIColor.lightGray
        noImagesLabel.shadowOffset = CGSize(width: 1.0, height: -1.0)
        
        
        // Check if there are images or not
        if photos.count == 0 {
            noImagesLabel.isHidden = false
        } else {
            noImagesLabel.isHidden = true
        }
        
        // Add the label to the UIView
        view.addSubview(noImagesLabel)

        
        navigationController?.navigationBar.tintColor = UIColor(rgbaHexString: "#2DBE60")
        navigationController?.title = "\(inpirationStore?.title)"
        
        collectionView.dataSource = self
        collectionView.delegate = self
        
    }

    override func viewDidLayoutSubviews() {
        super.viewDidLayoutSubviews()
        
        // calculate layout for collectionview
        let layout: UICollectionViewFlowLayout = UICollectionViewFlowLayout()
        layout.sectionInset = UIEdgeInsetsMake(0, 0, 0, 0)
        layout.minimumLineSpacing = 0
        layout.minimumLineSpacing = 1.0
        
        // update collectionview layout
        let width = floor(collectionView.frame.size.width/3)
        layout.itemSize = CGSize(width: width, height: width)
        collectionView.collectionViewLayout = layout
    }
    
    func UIColorFromRGB(rgbValue: UInt, alpha: CGFloat) -> UIColor {
        return UIColor(
            red: CGFloat((rgbValue & 0xFF0000) >> 16) / 255.0,
            green: CGFloat((rgbValue & 0x00FF00) >> 8) / 255.0,
            blue: CGFloat(rgbValue & 0x0000FF) / 255.0,
            alpha: CGFloat(alpha)
        )
    }
    // usage: UIColorFromRGB(0x0064A0, alpha: 1.0)
    
    
    

    

    
    // MARK: Navigation
    
    
    // MARK: Actions
    @IBAction func bottomBarButtonPressed(sender: AnyObject) {
        
        if selectedIndexes.isEmpty {
            photos.removeAll(keepingCapacity: true)
            collectionView.reloadData()
        }
        
    
    }
    
    
}


// MARK: CollectionView

extension ImageCollectionVC: UICollectionViewDataSource {

    func collectionView(_ collectionView: UICollectionView, numberOfItemsInSection section: Int) -> Int {
        return photos.count
    }
    
    func collectionView(_ collectionView: UICollectionView, cellForItemAt indexPath: IndexPath) -> UICollectionViewCell {
        let cell = collectionView.dequeueReusableCell(withReuseIdentifier: "CollectionViewCell", for: indexPath) as! CollectionViewCell
        
        let photoObject = photos[indexPath.row]
    
        if let photoImage = photoObject.image {
            cell.photoImage.image = photoImage
        } else {
            cell.photoImage.image = UIImage(named: "Placeholder")
        }
        
        return cell
    }
    
    func collectionView(_ collectionView: UICollectionView, didSelectItemAt indexPath: IndexPath) {
        
        
        let cell = collectionView.cellForItem(at: indexPath) as! CollectionViewCell
        
        if let index = selectedIndexes.index(of: indexPath as NSIndexPath) {
            selectedIndexes.remove(at: index)
            cell.photoImage.alpha = 1.0
            
        } else {
            selectedIndexes.append(indexPath as NSIndexPath)
            cell.photoImage.alpha = 0.2
        }
        
    }

}


// MARK: Collection View delegate Protocols
extension ImageCollectionVC: UICollectionViewDelegate {}


// MARK: UIImage picker protocols

enum SourceType: String {
    case camera = ".camera"
    case photoLibrary = ".photoLibrary"
}

extension ImageCollectionVC: UIImagePickerControllerDelegate, UINavigationControllerDelegate {

    func getImageFrom(_ source: UIImagePickerControllerSourceType) {
        let picker = UIImagePickerController()
        picker.delegate = self
        picker.sourceType = source
        present(picker, animated: true, completion: nil)
    }
    
    func imagePickerControllerDidCancel(_ picker: UIImagePickerController) {
            dismiss(animated: true, completion: nil)
    }
    
    func imagePickerController(_ picker: UIImagePickerController, didFinishPickingMediaWithInfo info: [String : Any]) {
        let image = info["UIImagePickerControllerOriginalImage"] as? UIImage
        guard let imageRef = image else { return }
        
        // add it to the photo library
        // photos.append(imageRef)
        picker.dismiss(animated: true, completion: nil)
    }
}

func addImage(_ image: UIImage) {
    let photo = Photo(image: image)
    
//    let photo = B2BPhoto(image: image)
//    let business = (self as?  B2BViewControllerProtocol)?.selectedBusiness
//    if business?.photos == nil { business?.photos = [B2BPhoto]() }
//    business?.photos?.append(photo)
}




