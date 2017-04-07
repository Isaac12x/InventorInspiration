//
//  MasterViewController.swift
//  InventorInspiration
//
//  Created by Isaac Ramonet on 22/03/2017.
//  Copyright © 2017 com.IsaacRamonet. All rights reserved.
//

import UIKit
import Redbeard

class MasterViewController: UIViewController, UITableViewDelegate, UITableViewDataSource, UINavigationControllerDelegate {

    // MARK: Properties
    
    @IBOutlet weak var tableView: UITableView!
    
    var detailViewController: DetailViewController? = nil
    var imageCollectionView: ImageCollectionVC? = nil
    var objects = [Any]()
    var inspireImageCollection = [InspireImageCollection]()
    var workspaceTitle: String? = "Tap to change title"
    
    // Control variables
    var keychainImplemented: Bool = false
    var isLocked: Bool = false
    
    
    // MARK: View lifecycle
    override func viewDidLoad() {
        super.viewDidLoad()
        setUp()
    }

    override func viewWillAppear(_ animated: Bool) {
       // self.clearsSelectionOnViewWillAppear = self.splitViewController!.isCollapsed
        super.viewWillAppear(animated)
    }

    
    func insertNewObject(_ sender: Any) {
        
        // Create an alert
        let alert = UIAlertController(title: "Add a title", message: "", preferredStyle: UIAlertControllerStyle.alert)

        // Use the textfield builtin spec
        alert.addTextField { (textField) in
            textField.text = "Workspace title"
        }
        
        // Add action to the alert
        let doneAction = UIAlertAction(title: "Done", style: UIAlertActionStyle.default, handler: { [weak alert] (_) in
            
            // get the text from the textfield
            if let wTitle = alert?.textFields?[0] {
               
                // add the text to a title
                self.workspaceTitle = "\(wTitle.text)"
                
                self.tableView.reloadData()
            }
        })
        
        alert.addAction(doneAction)
        self.present(alert, animated: true, completion: nil)
        
        
        // Change this for a configured cll
        objects.insert(NSDate(), at: 0)
        let indexPath = IndexPath(row: 0, section: 0)
        self.tableView.insertRows(at: [indexPath], with: .automatic)
    }

    // MARK: - Segues

    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        if segue.identifier == "showDetail" {
            if let indexPath = self.tableView.indexPathForSelectedRow {
                let object = objects[indexPath.row] as! NSDate
                let controller = (segue.destination as! UINavigationController).topViewController as! DetailViewController
                controller.detailItem = object
                controller.navigationItem.leftBarButtonItem = self.splitViewController?.displayModeButtonItem
                controller.navigationItem.leftItemsSupplementBackButton = true
            }
        }
    }

    // MARK: - Table View

    func numberOfSections(in tableView: UITableView) -> Int {
        return 1
    }

    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return objects.count
    }

    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        // reference the cell
        let cell = tableView.dequeueReusableCell(withIdentifier: "inspirationCell", for: indexPath)

        // create the object to iterate over
        // var object: [inspireImageCollection]?
        
        // get the indexpath of the collection -- fails here because there is no object
        if inspireImageCollection.isEmpty {
            
            // create the object 
            
            
            //  download an image form web and configure the immage
            cell.imageView?.downloadedFrom(link: "https://unsplash.it/200/300/?random")

            // object =
            
            
        } else {
            // search in each row
            let object = inspireImageCollection[indexPath.row]
            
            // configure the cell
            cell.textLabel?.text = object.title
            cell.imageView?.image = object.inspireCollection?.first?.image
            
        }
        
        
        
        // if title is empty
        if workspaceTitle == "" {
            // add a button and allow the user to change it
            let button = UIButton(frame: CGRect(x: 80, y: 20, width: 150, height: 30))
            button.setTitle("Press somewhere to edit", for: UIControlState.normal)
            button.addTarget(self, action: #selector(MasterViewController.changeWorkspaceTitle), for: UIControlEvents.touchUpInside)
            
            // I need a delegate here
            
            cell.textLabel?.text = ""
            // add the button to the view
            self.view.addSubview(button)
        } else {
            cell.textLabel?.text = "\(workspaceTitle)"
        }
        
        return cell
    }
    
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        tableView.allowsSelectionDuringEditing = false
        
        let controller = storyboard!.instantiateViewController(withIdentifier: "ManagerNavigationController") as? UINavigationController
        present(controller!, animated: true, completion: nil)

    }

    func tableView(_ tableView: UITableView, canEditRowAt indexPath: IndexPath) -> Bool {
        // Return false if you do not want the specified item to be editable.
        return true
    }

    func tableView(_ tableView: UITableView, commit editingStyle: UITableViewCellEditingStyle, forRowAt indexPath: IndexPath) {
        if editingStyle == .delete {
            let alertController = UIAlertController(title: "Wait", message: "All your images will be deleted. Are you sure you want to continue?", preferredStyle: UIAlertControllerStyle.alert)
            let defaultAction = UIAlertAction(title: "Yes", style: .destructive, handler: { (action) in
                self.objects.remove(at: indexPath.row)
                tableView.deleteRows(at: [indexPath], with: .fade)
            })
            let cancelAction = UIAlertAction(title: "No", style: .cancel, handler: { (action) in
                self.dismiss(animated: true, completion: nil)
            })
            alertController.addAction(defaultAction)
            alertController.addAction(cancelAction)
            
            self.present(alertController, animated: true, completion: nil)

            
        } else if editingStyle == .insert {
            // Create a new instance of the appropriate class, insert it into the array, and add a new row to the table view.
            let newImaginationSpaceCell = tableView.dequeueReusableCell(withIdentifier: "Cell", for: indexPath)
            let inspirationCollection = inspireImageCollection[indexPath.row]
        
            newImaginationSpaceCell.imageView?.image = UIImage(cgImage: inspirationCollection.inspireCollection?.first as! CGImage)
            newImaginationSpaceCell.textLabel?.text = "Touch to configure"
        }
    }
    
    
    // MARK: Helper functions
    
    func showAlert(_ title: String, message: String, actionTitle: String) {
        let alertController = UIAlertController(title: title, message: message, preferredStyle: UIAlertControllerStyle.alert)
        let defaultAction = UIAlertAction(title: actionTitle, style: .cancel, handler: nil)
        alertController.addAction(defaultAction)
        self.present(alertController, animated: true, completion: nil)
    }
    

    // TODO: Implement locking ability
    func lockApp() {
        let lockVC = storyboard?.instantiateViewController(withIdentifier: "LockingVC") as! LockingVC
        navigationController?.pushViewControllerFromTop(viewController: lockVC)
    }

    
    func changeWorkspaceTitle() {
        // Create an alert
        let alert = UIAlertController(title: "Add a title", message: "", preferredStyle: UIAlertControllerStyle.alert)
        
        // Use the textfield builtin spec
        alert.addTextField { (textField) in
            textField.text = "Workspace title"
        }
        
        // Add action to the alert
        let doneAction = UIAlertAction(title: "Done", style: UIAlertActionStyle.default, handler: { [weak alert] (_) in
            // get the text from the textfield
            if let wTitle = alert?.textFields?[0] {
                // add the text to a title
                self.workspaceTitle = "\(wTitle.text)"
            }
        })
        
        alert.addAction(doneAction)
        self.present(alert, animated: true, completion: { (action) in
            self.tableView.reloadData()
        })

    }
}


extension MasterViewController {
    
    func setUp() {
        // Configure the navigation
        self.navigationItem.leftBarButtonItem = self.editButtonItem
        let addButton = UIBarButtonItem(barButtonSystemItem: .add, target: self, action: #selector(insertNewObject(_:)))
        self.navigationItem.rightBarButtonItem = addButton
        // Better to put an image here :D
        self.navigationController?.title = "II"
        
        // Navigation logo
        let image = UIImage(named: "naviLogo")
        let navLogo = UIImageView(image: image)
        navLogo.frame = CGRect(x: 0, y: 0, width: 10, height: 20)
        self.navigationItem.titleView = navLogo
        
        
        
        // Add a locker to the left of the navigation
        let lockButton = UIBarButtonItem(image: UIImage(named: "Lock"), landscapeImagePhone: UIImage(named: "Lock"), style: UIBarButtonItemStyle.plain, target: self, action: #selector(MasterViewController.lockApp))
        self.navigationItem.leftBarButtonItem = lockButton
        
        
        
        
        // If we have a split view change the configuration
        if let split = self.splitViewController {
            let controllers = split.viewControllers
            self.detailViewController = (controllers[controllers.count-1] as! UINavigationController).topViewController as? DetailViewController
        }
        
        // if tableview is empty
        if inspireImageCollection.isEmpty {
            // create a translucent overlay with calayer
            let translucentLayer = CALayer()
            
            // configure the layer
            translucentLayer.backgroundColor = UIColor(red: 128, green: 128, blue: 128, alpha: 0.7).cgColor
            
            // Add a circle in the path so it leaves the barbuttonitem
//            let radius = 
//            let path = UIBezierPath(roundedRect: CGRect(x: 0, y: 0, width: self.lockButton.bounds.size.width, height: self.mapView.bounds.size.height), cornerRadius: 0)
//            let circlePath = UIBezierPath(roundedRect: CGRect(x: 0, y: 0, width: 2 * radius, height: 2 * radius), cornerRadius: radius)
//            path.append(circlePath)
//            path.usesEvenOddFillRule = true
//            
//            let fillLayer = CAShapeLayer()
//            fillLayer.path = path.cgPath
//            fillLayer.fillRule = kCAFillRuleEvenOdd
//            fillLayer.fillColor = UIColor(red: 128, green: 128, blue: 128, alpha: 0.7).cgColor
//            fillLayer.opacity = 0.5
//            view.layer.addSublayer(fillLayer)
//            
            
            // add the subview to the main view
            self.view.layer.insertSublayer(translucentLayer, at: 0)
            
            // add an image on the top of the overlay
            
            // animate the image so it points to the hole
            
            // add the image to the view
        }
    }
}


extension MasterViewController: UITextFieldDelegate {

    func textFieldDidBeginEditing(_ textField: UITextField) {
        textField.text = ""
    }
    
}
