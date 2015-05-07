<?php

/* 
 * This is the models file
 * All connections to thge database for collecting data is performed in this file
 */

  function headless_api_nodes($type = 'article') {
      
    $nodes = node_load_multiple(array(), array('type' => $type, 'status' => 1)); 
    //echo "this works " . $nodes;
    //print_r($nodes);
    
    $export = array();  
#sanitise
    
    $counter = 0;
    foreach($nodes as $row) {
        $export[$counter]['title'] = $row->title;
        $export[$counter]['type'] = $row->type;
        $export[$counter]['created'] = $row->created;
        $export[$counter]['body'] = $row->body['und'][0]['value'];
        $counter++;
    }

    
    $export = (object) $export;
      
      drupal_json_output($export);
  }
  
function headless_api_test() {
    global $base_url; 
        $testData['title'] = 'Marks Test Data';
        $testData['body'] = 'Some Data to hold in place describing this';
        $testData['site'] = $base_url;
        $testData['image'] = 'http://www.clipartbest.com/cliparts/niX/baL/niXbaLGiB.jpeg';
        
      
      drupal_json_output($testData);
  }