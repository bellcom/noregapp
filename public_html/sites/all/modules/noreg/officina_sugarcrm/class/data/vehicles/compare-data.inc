<?php

// Compare node data
function _sugarcrm_compare_node_data_vehicles($node, $entry) {


    if ($node->field_vehicle_customer_id['und'][0]['value'] != $entry->case_id) {
        return FALSE;
    }


    if ($node->field_vehicle_description['und'][0]['value'] != utf8_encode($entry->description)) {
        return FALSE;
    }

    // No errors
    return TRUE;

}