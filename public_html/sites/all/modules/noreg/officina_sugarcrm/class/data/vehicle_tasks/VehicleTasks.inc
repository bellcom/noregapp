<?php

class VehicleTasks extends SugarBase {

    private $name;
    private $invoiceno;
    private $orderno;
    private $km;
    private $status;
    private $date_start;
    private $bc_vehicles_id;


    function __set($name, $value) {

        if (property_exists($this, $name)) {
            $this->$name = $value;
        }
    }

    function __get($name) {

        if (property_exists($this, $name)) {
            return $this->$name;
        }
    }
}