<?php

/**
 * Manage vehicles
 * @param $entry
 */
function _sugarcrm_manage_vehicles($entry) {

    //check if exists
    $query  = new EntityFieldQuery();
    $result = $query
        ->entityCondition('entity_type', 'node')
        ->entityCondition('bundle', 'vehicles')
        ->fieldCondition('field_vehicle_sugarcrm_id', 'value', $entry->id, '=')
        ->execute();

    // Result
    if ($result) {

        // Already exists - update
        $param = array_keys($result['node']);
        $node = node_load(array_shift($param));

        // Is node
        if ($node != FALSE) {

            // Some data does not match
            if (_sugarcrm_compare_node_data_vehicles($node, $entry) == FALSE) {

                // Set fields
                $node = _sugarcrm_set_node_fields_vehicles($node, $entry);

                // Save
                node_save($node);

                // Add relationship to assignment
                //_sugarcrm_bind_timestamp_to_vehicles($node);

            }
        }
    }

    // No result
    else {

        // Create node
        $node = _sugarcrm_create_node_vehicles($entry);

        // Save node
        $node = node_submit($node);
        node_save($node);

        // Add relationship to assignment
        //_sugarcrm_bind_timestamp_to_vehicles($node);

    }

    $query = NULL;
    $result = NULL;

}