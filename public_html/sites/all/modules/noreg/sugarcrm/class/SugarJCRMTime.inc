<?php

class SugarJCRMTime extends SugarModel{
    private $date_modified;
    private $case_id;
    private $case_name;
    private $account_id;
    private $account_name;
    private $date;
    private $time_start;
    private $time_end;
    private $time_length;
    private $voucher_id;
    private $voucher_number;
    private $team_id;
    private $inv_comment;
    private $category;
    private $inv_checked;

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