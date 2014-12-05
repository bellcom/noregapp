<?php

class Vehicle extends SugarBase {


    private $name;
    private $serialno;
    private $gearboxno;
    private $motorno;
    private $rearaxle;
    private $registrationdate;
    private $typeno;
    private $regno;


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