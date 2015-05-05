<?php

/* 
 * This is the backend controller file.
 * This is where the functions are used to link the views to the models
 * Currently is procedural
 */


#parse type through to theme
function headless_api_page($type = 'article') {
    
    #information to be parsed through to theme template
    $data = array('type' => $type);
    
    return theme('page_v1', array('data' => $data));
    
}