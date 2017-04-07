//
//  SettingsViewController.swift
//  InventorInspiration
//
//  Created by Isaac Albets Ramonet on 05/04/2017.
//  Copyright © 2017 com.IsaacRamonet. All rights reserved.
//

import UIKit

class SettingsViewController: UITableViewController {

    
    // MARK: Properties
    // Control variables
    let sections = ["General Settings", ""]
    
    let optionTitles = [["Locking enabled?", "Display Notes?", "Quick Presentation?", "Allow downloading images?"], ["Attributions", "Policy"]]
    var locking = false
    var diplaynotes = false
    var quickPresentation = false
    var allowInternetImages = false
    
    // Store variables
    var settingsDictionary = ["Locking enabled?": false, "Display Notes?": false, "Quick Presentation?": false, "Allow downloading images?": false]
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        navigationItem.titleView = UIImageView(image: UIImage(named: ""))
        
        if "some condition" != nil {
            // grab the saved data
        } else if "it's fresh" != ""{
            // load as a new start
        } else {
            // show alert that something is failing - should never be executed
        }
        
        // Uncomment the following line to preserve selection between presentations
        // self.clearsSelectionOnViewWillAppear = false
        
        // Uncomment the following line to display an Edit button in the navigation bar for this view controller.
        // self.navigationItem.rightBarButtonItem = self.editButtonItem()
    }
    
    
    // MARK: - Table view data source
    
    override func numberOfSections(in tableView: UITableView) -> Int {
        return sections.count
    }
    
    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return optionTitles[section].count
    }
    
    
    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "AdminCell", for: indexPath) as! AdminCell
        
        // Grab the object
        let obj = optionTitles[indexPath.section][indexPath.row]
        
        // Configure each title
        cell.title?.text = obj
        cell.switcher.isOn = false
        
        return cell
    }
    
    
    
    override func tableView(_ tableView: UITableView, titleForHeaderInSection section: Int) -> String? {
        return sections[section]
    }
    
    
    func changePreferences(sender: UISwitch) {
    
        let currentSwitch: UISwitch = UISwitch()
        
        // on change vibrate
        UIDevice.vibrate()
    }
    /*
     // Override to support editing the table view.
     override func tableView(_ tableView: UITableView, commit editingStyle: UITableViewCellEditingStyle, forRowAt indexPath: IndexPath) {
     if editingStyle == .delete {
     // Delete the row from the data source
     tableView.deleteRows(at: [indexPath], with: .fade)
     } else if editingStyle == .insert {
     // Create a new instance of the appropriate class, insert it into the array, and add a new row to the table view
     }
     }
     */
    
    /*
     // Override to support rearranging the table view.
     override func tableView(_ tableView: UITableView, moveRowAt fromIndexPath: IndexPath, to: IndexPath) {
     
     }
     */
    
    /*
     // Override to support conditional rearranging of the table view.
     override func tableView(_ tableView: UITableView, canMoveRowAt indexPath: IndexPath) -> Bool {
     // Return false if you do not want the item to be re-orderable.
     return true
     }
     */
    
    /*
     // MARK: - Navigation
     
     // In a storyboard-based application, you will often want to do a little preparation before navigation
     override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
     // Get the new view controller using segue.destinationViewController.
     // Pass the selected object to the new view controller.
     }
     */
    

}
