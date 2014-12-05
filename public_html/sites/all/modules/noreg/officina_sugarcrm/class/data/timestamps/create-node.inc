<?php

/**
 * Creates node from given SugarJCRMTime.
 * @param $entry SugarJCRMTime
 * @return StdClass
 */
function _sugarcrm_create_node_timestamps($entry) {

    $node = new StdClass();
    $node->type = 'timestamps';
    $node->promote = 0;
    node_object_prepare($node);

    $node->title = 'Timestamp';
    $node->status = 1;
    $node->language = LANGUAGE_NONE;
    $node = _sugarcrm_set_node_fields_timestamps($node, $entry);
    return $node;

}