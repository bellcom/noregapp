<?php

function _sugarcrm_bind_vehicle_task_to_vehicle($node){

    $query = new EntityFieldQuery();
    $result = $query
        ->entityCondition('entity_type', 'node')
        ->entityCondition('bundle', 'vehicles')
        ->fieldCondition('field_task_sugarcrm_id', 'value', $node->field_task_vehicle_id['und'][0]['value'], '=')
        ->execute();

    if($result){
        //exist
        $param = array_keys($result['node']);
        $node->field_task_vehicle['und'][0]['target_id'] = array_shift($param);
        node_save($node);
        $node = null;
    }

    $query = null;
    $result = null;

}