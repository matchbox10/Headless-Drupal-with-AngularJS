<?php

/* This is a non-Drupal style template that will show how to connect with the Json Feed*/

?>
<body ng-controller="ArticleList">
    <h1>Test Shit!</h1>
    <p><?php print_r($data); ?></p>
  <ul>
    <li ng-repeat="article in articles">
      <span>{{article.title}}</span>
      <p>{{article.body}}</p>
    </li>
  </ul>

</body>