<?php

/* This is a non-Drupal style template that will show how to connect with the Json Feed*/

?>
<html ng-app="drupalArticleApp">
<head>
    <?php print $scripts['script']; ?>
    <?php print $data['style']; ?>
</head>
<body ng-controller="ArticleListCtrl">
    <h1>Test Node Exports!</h1>
  
    <p><?php //print_r($data); ?></p>
    Search: <input ng-model="query">
    Sort by: <select ng-model="orderProp">
      <option value="title">Alphabetical</option>
      <option value="created">Newest</option>
    </select>
    <ul class="articles">
    <li ng-repeat="article in articles | filter:query | orderBy:orderProp">
      <h3>{{article.title}}</h3>
      <p>{{article.body}}</p>
    </li>
  </ul>
</body>
</html>