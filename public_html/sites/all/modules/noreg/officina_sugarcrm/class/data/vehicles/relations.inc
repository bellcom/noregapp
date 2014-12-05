<?php

function _sugarcrm_bind_timestamp_to_vehicles($node){

    $query = new EntityFieldQuery();
    $result = $query
        ->entityCondition('entity_type', 'node')
        ->entityCondition('bundle', 'sugarcrm_case')
        ->fieldCondition('field_sugar_id', 'value', $node->field_sugar_case_id['und'][0]['value'], '=')
        ->execute();

    if($result){
        //exist
        $param = array_keys($result['node']);
        $node->field_sugar_case['und'][0]['target_id'] = array_shift($param);
        node_save($node);
        $node = null;
    }

    $query = null;
    $result = null;

}