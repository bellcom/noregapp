<?php

class Timestamps extends SugarBase {

    private $time_start;
    private $time_end;

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