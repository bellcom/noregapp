<?php


// Convert date
function _sugarcrm_convert_date($date) {
    $time = strtotime($date);
    return date("Y-m-d H:i:s", $time);
}