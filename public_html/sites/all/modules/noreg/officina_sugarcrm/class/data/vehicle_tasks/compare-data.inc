<?php

// Compare node data
function _sugarcrm_compare_node_data_vehicle_tasks($node, $entry) {


    if ($node->field_sugar_case_id['und'][0]['value'] != $entry->case_id) {
        return FALSE;
    }


    if ($node->field_sugar_description['und'][0]['value'] != utf8_encode($entry->description)) {
        return FALSE;
    }

    // No errors
    return TRUE;

}