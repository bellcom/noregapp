<?php

/**
 * Sets fields of given node
 * @param $node
 * @param $entry SugarJCRMTime
 * @return mixed
 */
function _sugarcrm_set_node_fields_timestamps($node, $entry) {

    // SugarCRM ID
    $node->field_timestamp_sugarcrm_id[$node->language][0]['value']   = $entry->id;

    // Task ID
    $node->field_timestamp_vehicle_task_id[$node->language][0]['value'] = $entry->task_id;

    // Time start
    $node->field_timestamp_stamps[$node->language][0]['value']        = _sugarcrm_convert_date($entry->time_start);

    // Time end
    $node->field_timestamp_stamps[$node->language][0]['value2']       = _sugarcrm_convert_date($entry->time_end);

    // Return the node
    return $node;

}