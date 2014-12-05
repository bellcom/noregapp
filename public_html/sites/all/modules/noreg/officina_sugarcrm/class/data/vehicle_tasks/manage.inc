<?php

/**
 * Manage vehicle_tasks
 * @param $entry
 */
function _sugarcrm_manage_vehicle_tasks($entry) {

    //check if exists
    $query  = new EntityFieldQuery();
    $result = $query
        ->entityCondition('entity_type', 'node')
        ->entityCondition('bundle', 'vehicle_tasks')
        ->fieldCondition('field_task_sugarcrm_id', 'value', $entry->id, '=')
        ->execute();

    // Result
    if ($result) {

        // Already exists - update
        $param = array_keys($result['node']);
        $node = node_load(array_shift($param));

        // Is node
        if ($node != FALSE) {

            // Some data does not match
            if (_sugarcrm_compare_node_data_vehicle_tasks($node, $entry) == FALSE) {

                // Set fields
                $node = _sugarcrm_set_node_fields_vehicle_tasks($node, $entry);

                // Save
                node_save($node);

                // Add relationship to assignment
                //_sugarcrm_bind_timestamp_to_vehicle_tasks($node);

            }
        }
    }

    // No result
    else {

        // Create node
        $node = _sugarcrm_create_node_vehicle_tasks($entry);

        // Save node
        $node = node_submit($node);
        node_save($node);

        // Add relationship to assignment
        //_sugarcrm_bind_timestamp_to_vehicle_tasks($node);

    }

    $query = NULL;
    $result = NULL;

}