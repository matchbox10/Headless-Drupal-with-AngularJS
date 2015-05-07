<?php

/* 
 * This is the backend controller file.
 * This is where the functions are used to link the views to the models
 * Currently is procedural
 */

#load header scripts into template
function headless_create_head($header = 'script') {
    $data ='';
    if($header == 'script') {
        $headLibraries = headless_set_libraries();
        foreach($headLibraries['js'] as $createLibrary) :
            $data .= '<script src="' . $createLibrary . '"></script>';
        endforeach;
    } elseif($header == 'style1') {
        $data = '<style type="text/css" media="all">';
        foreach($headLibraries['css'] as $createLibrary) :
            $data .= '@import url("' . $createLibrary . '");';
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
    $data['js']['angularJS'] = $module_path . '/libraries/angular.min.js';
    $data['js']['angularController'] = $module_path . '/' . 'js/controllers.js';
    
    $data['css']['main'] = $module_path . '/' . 'css/main.css';
    
    return $data;
    
}

#include styles. These can be Less or CSS
function headless_set_styles() {
    return '<style></style>';
}


#parse type through to theme
function headless_api_page($type = 'article') {
    
    #set data to be parsed to template
    $scripts['script'] = headless_create_head('script');
    $scripts['style'] = headless_create_head('style');
    
    #Set Styles
    $styles = headless_set_styles();
    $data = 'Test';
    
    #information to be parsed through to theme template
    $data = array('type' => $type,
        'data' => $data,
        'css' => 'css');
    
    print theme('page_v1', array('data' => $data, 'scripts' => $scripts));
    
}