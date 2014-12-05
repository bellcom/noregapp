<?php

/**
 * Sets fields of given node
 * @param $node
 * @param $entry SugarJCRMTime
 * @return mixed
 */
function _sugarcrm_set_node_fields_vehicles($node, $entry) {

    // Type number
    $node->title                                                            = htmlentities($entry->typeno);

    // Name
    $node->field_vehicle_name[$node->language][0]['value']                  = htmlentities($entry->name);

    // SugarCRM ID
    $node->field_vehicle_sugarcrm_id[$node->language][0]['value']           = $entry->id;

    // Description
    $node->field_vehicle_description[$node->language][0]['value']           = htmlentities($entry->description);

    // Serial number
    $node->field_vehicle_serial_number[$node->language][0]['value']         = htmlentities($entry->serialno);

    // Gearbox number
    $node->field_vehicle_gearbox_number[$node->language][0]['value']        = $entry->gearboxno;

    // Motor number
    $node->field_vehicle_motor_number[$node->language][0]['value']          = $entry->motorno;

    // Rear axle number
    $node->field_vehicle_rear_axle_number[$node->language][0]['value']      = $entry->rearaxle;

    // Registration date
    $node->field_vehicle_registration_date[$node->language][0]['value']     = $entry->regdate ? _sugarcrm_convert_date($entry->regdate) : NULL;

    // Registration number
    $node->field_vehicle_registration_numbe[$node->language][0]['value']    = htmlentities($entry->regno);

    // Return the node
    return $node;

}