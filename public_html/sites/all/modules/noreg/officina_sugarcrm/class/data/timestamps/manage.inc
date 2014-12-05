<?php

/**
 * Manage timestamps
 * @param $entry
 */
function _sugarcrm_manage_timestamps($entry) {

    //check if exists
    $query  = new EntityFieldQuery();
    $result = $query
        ->entityCondition('entity_type', 'node')
        ->entityCondition('bundle', 'timestamps')
        ->fieldCondition('field_timestamp_sugarcrm_id', 'value', $entry->id, '=')
        ->execute();

    // Result
    if ($result) {

        // Already exists - update
        $param = array_keys($result['node']);
        $node = node_load(array_shift($param));

        // Is node
        if ($node != FALSE) {

            // Some data does not match
            if (_sugarcrm_compare_node_data_timestamps($node, $entry) == FALSE) {

                // Set fields
                $node = _sugarcrm_set_node_fields_timestamps($node, $entry);

                // Save
                node_save($node);

                // Add relationship to task
                _sugarcrm_bind_timestamp_to_vehicle_task($node);

            }
        }
    }

    // No result
    else {

        // Create node
        $node = _sugarcrm_create_node_timestamps($entry);

        // Save node
        $node = node_submit($node);
        node_save($node);

        // Add relationship to task
        _sugarcrm_bind_timestamp_to_vehicle_task($node);

    }

    $query = NULL;
    $result = NULL;

}