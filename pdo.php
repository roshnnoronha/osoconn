<?php
$pdo = new PDO('sqlite:./common/AISCSections.db');
$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);