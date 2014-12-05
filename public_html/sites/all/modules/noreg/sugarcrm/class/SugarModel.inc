<?php

abstract class SugarModel {
    protected $id;
    protected $assigned_user_name;
    protected $modified_by_name;
    protected $created_by_name;
    protected $date_entered;
    protected $modified_user_id;
    protected $modified_user_name;
    protected $created_by;
    protected $description;
    protected $deleted;
    protected $assigned_user_id;

    function __construct($data)
    {
        foreach ($data as $d) {
            $this->$d['name'] = $d['value'];
        }

    }

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