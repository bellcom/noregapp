<?php

/**
 * Creates node from given SugarJCRMTime.
 * @param $entry SugarJCRMTime
 * @return StdClass
 */
function _sugarcrm_create_node_vehicles($entry) {

    $node = new StdClass();
    $node->type = 'vehicles';
    $node->promote = 0;
    node_object_prepare($node);

    $node->status = 1;
    $node->language = LANGUAGE_NONE;
    $node = _sugarcrm_set_node_fields_vehicles($node, $entry);
    return $node;

}