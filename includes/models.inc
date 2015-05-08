<?php

/* 
 * This is the models file
 * All connections to thge database for collecting data is performed in this file
 */

  function headless_api_nodes($type = 'article') {
      
    $nodes = node_load_multiple(array(), array('type' => $type, 'status' => 1)); 
    //echo "this works " . $nodes;
    //print_r($nodes);
    $records = new stdClass();
    $export = array();
#sanitise
    
    $counter = 0;
    foreach($nodes as $row) {
        $export[] = array('title' => $row->title, 'type' => $row->type, 'created' => $row->created, 'body' => $row->body['und'][0]['value']);
        $counter++;
    }

    
    $records->records = $export;
      
      drupal_json_output($records);
  }
  
  #export the blocks
  function headless_api_blocks($region = 'content') {
      
       $records = new stdClass();
      $result = db_query('SELECT
block_custom.body,
block.title,
block.region,
block_custom.info,
block.weight,
block.`status`
FROM
block
INNER JOIN block_custom ON block_custom.bid = block.bid
WHERE
block.`status` = 1 
ORDER BY block.weight ASC', array(':region' => $region));
      
        foreach($result as $row) {
            $export[] = array('title' => $row->info, 'body' => $row->body, 'region' => $row->region);

    }
   // print_r($result);
    $records->records = $export;
     drupal_json_output($records);
  }
  
  
function headless_api_test() {
    global $base_url; 
        $testData['title'] = 'Marks Test Data';
        $testData['body'] = 'Some Data to hold in place describing this';
        $testData['site'] = $base_url;
        $testData['image'] = 'http://www.clipartbest.com/cliparts/niX/baL/niXbaLGiB.jpeg';
        
      
      drupal_json_output($testData);
  }