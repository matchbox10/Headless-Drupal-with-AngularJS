<?php

/* 
 * This is the backend controller file.
 * This is where the functions are used to link the views to the models
 * Currently is procedural
 */

#load header scripts into template
function headless_create_head($header = 'script') {
    
    if($header == 'script') {
        $headLibraries = headless_set_libraries();
        foreach($headLibraries as $createLibrary) :
            $data .= '<script src="' . $headLibraries . '"></script>';
        endforeach;
    } elseif($header == 'style') {
        $data = '<style type="text/css" media="all">';
                foreach($headLibraries as $createLibrary) :
            $data .= '@import url("' . $headLibraries . '");';
        endforeach;
        $data .= '</style>';
    }
    return $data;
}


#Set Libraries for headers to allow AngularJS
function headless_set_libraries() {
    global $base_url;
    
    #Get path to module
    $module_path = $base_url . "/" . drupal_get_path('module', 'headless_api');
    
    #get libraries to include
    $data['angularJS'] = $module_path . '/libraries/angular.min.js';
    $data['angularController'] = $module_path . '/' . 'js/controllers.js';
    
    
    return $data;
    
}

#include styles. These can be Less or CSS
function headless_set_styles() {
    return '<style></style>';
}


#parse type through to theme
function headless_api_page($type = 'article') {
    
    #set data to be parsed to template
    $headers['script'] = headless_create_head('script');
    $headers['style'] = headless_create_head('style');
    
    
    #Set Styles
    $styles = headless_set_styles();
    $data = array('test');
    
    #information to be parsed through to theme template
    $data = array('type' => $type,
        'data' => $data,
        'scripts' => array('head' => $headers),
        'css' => 'css');
    
    print theme('page_v1', array('data' => $data));
    
}