<?php

class Connector {


    // Name of modules inside SugarCRM
    const TIMESTAMPS            = 'bc_Time'; // ed.: tidsstempler
    const VEHICLES              = 'bc_Vehicles'; // ed.: køretøjer
    const ACCOUNTS              = 'Accounts'; // ed.: kunder
    const VEHICLE_TASKS         = 'bc_Vehicletask'; // ed.: køretøjsopgaver

    // Configurations
    const MAX_NUMBER_OF_ROWS = 300;
    const URL_ADDRESS = 'http://crm.noreg.dk/soap.php?wsdl';

    private $url_address;
    private $username;
    private $password;

    private $client;
    private $session_id;

    function __construct($url_address, $username, $password) {
        $this->url_address = $url_address;
        $this->password = $password;
        $this->username = $username;
    }

    public function connect() {
        $this->client = new nusoap_client($this->url_address, 'wsdl');
        if ($this->client->getError()) {
            throw new Exception($this->client->getDebug());
        }
        $this->login();
    }

    private function login() {
        $login_parameters = array(
          'user_auth' => array(
            'user_name' => $this->username,
            'password' => md5($this->password),
            'version' => '1'
          ),
          'application_name' => 'SoapTest',
          'name_value_list' => array(),
        );

        $login_result = $this->client->call('login', $login_parameters);
        if ($login_result['id'] == -1) {
            throw new Exception($login_result['error']['description']);
        }
        $this->session_id = $login_result['id'];
        return $login_result;
    }


    public function get_entry_list($module_name, $offset = 0, $rows = self::MAX_NUMBER_OF_ROWS){
        $get_entry_list_parameters = array(
            //session id
          'session' => $this->session_id,
            //The name of the module from which to retrieve records
          'module_name' => $module_name,
            //The SQL WHERE clause without the word “where”.
          'query' => "",
            //The SQL ORDER BY clause without the phrase “order by”.
          'order_by' => "",
            //The record offset from which to start.
          'offset' => $offset,
            //The maximum number of results to return.
          'max_results' => $rows,
            //To exclude deleted records
          'deleted' => 0,
            //If only records marked as favorites should be returned.
          'Favorites' => false,
        );
        $get_entry_list_result = $this->client->call("get_entry_list", $get_entry_list_parameters);
        return $get_entry_list_result;
    }


    /**
     * @return array
     */
    public function get_timestamps($offset = 0, $rows = self::MAX_NUMBER_OF_ROWS) {

        $get_entry_list_result = $this->get_entry_list(self::TIMESTAMPS, $offset, $rows);

        $list = array();

        foreach ($get_entry_list_result['entry_list'] as $entry) {
            $list[] = new Timestamps($entry['name_value_list']);
        }

        return $list;
    }


    /**
     * @return array
     */
    public function get_vehicle_tasks($offset = 0, $rows = self::MAX_NUMBER_OF_ROWS) {

        $get_entry_list_result = $this->get_entry_list(self::VEHICLE_TASKS, $offset, $rows);

        $list = array();

        foreach ($get_entry_list_result['entry_list'] as $entry) {
            $list[] = new VehicleTasks($entry['name_value_list']);
        }

        return $list;
    }


    /**
     * @return array
     */
    public function get_vehicles($offset = 0, $rows = self::MAX_NUMBER_OF_ROWS) {

        $get_entry_list_result = $this->get_entry_list(self::VEHICLES, $offset, $rows);

        $list = array();

        foreach ($get_entry_list_result['entry_list'] as $entry) {
            $list[] = new Vehicle($entry['name_value_list']);
        }

        return $list;
    }

}