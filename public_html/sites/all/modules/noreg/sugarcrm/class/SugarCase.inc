<?php

class SugarCase extends SugarModel{
    private $date_modified;
    private $case_number;
    private $type;
    private $priority;
    private $resolution;
    private $work_log;
    private $account_name;
    private $account_id;
    private $min_inv_time_c;
    private $max_hours_c;
    private $accept_overrun_c;
    private $rest_hours_c;
    private $reg_hours_c;
    private $name;
    private $status;

    function __set($name, $value)
    {
        if(property_exists($this, $name))
            $this->$name = $value;
    }

    function __get($name)
    {
        if(property_exists($this, $name))
            return $this->$name;
    }
} 