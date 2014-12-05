<?php

/**
 * Sets fields of given node
 * @param $node
 * @param $entry SugarJCRMTime
 * @return mixed
 */
function _sugarcrm_set_node_fields_vehicle_tasks($node, $entry) {

    // Name
    $node->title                                                        = htmlentities($entry->name);

    // SugarCRM ID
    $node->field_task_sugarcrm_id[$node->language][0]['value']          = $entry->id;

    // Vehicle SugarCRM ID
    //$node->field_task_vehicle_id[$node->language][0]['value']           = $entry->id;

    // Invoice number
    $node->field_task_invoice_number[$node->language][0]['value']       = $entry->invoiceno;

    // Order number
    $node->field_task_order_number[$node->language][0]['value']         = $entry->orderno;

    // KM/hours
    $node->field_task_km_hours[$node->language][0]['value']             = $entry->km;

    // Status
    $node->field_task_current_status[$node->language][0]['value']       = $entry->status;

    // Starting date
    $node->field_task_starting_date[$node->language][0]['value']        = $entry->date_start ? _sugarcrm_convert_date($entry->date_start) : NULL;


    // TODO


    error_log( print_r( $entry, true ) );

    // Return the node
    return $node;

}