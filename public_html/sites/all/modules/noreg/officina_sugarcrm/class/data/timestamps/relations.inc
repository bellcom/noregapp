<?php

function _sugarcrm_bind_timestamp_to_vehicle_task($node){

    $query = new EntityFieldQuery();
    $result = $query
        ->entityCondition('entity_type', 'node')
        ->entityCondition('bundle', 'vehicle_tasks')
        ->fieldCondition('field_task_sugarcrm_id', 'value', $node->field_timestamp_vehicle_task_id['und'][0]['value'], '=')
        ->execute();

    if($result){
        //exist
        $param = array_keys($result['node']);
        $node->field_timestamp_vehicle_task_id['und'][0]['target_id'] = array_shift($param);
        node_save($node);
        $node = null;
    }

    $query = null;
    $result = null;

}