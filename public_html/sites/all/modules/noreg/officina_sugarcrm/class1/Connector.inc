<?php

class Connector {

    const TASKS = 'Tasks'; // ed.: opgaver
    const TIMESTAMPS = 'Timestamps'; // ed.: tid

    const VEHICLES = 'Vehicles'; // Ed køretøjer
    const MATERIALS = 'Materials'; // ed materialer


    const ACCOUNTS = 'Accounts';
    const MAX_ROWS = 300;

    private $url = "http://crm.noreg.dk/soap.php?wsdl";
    private $username;
    private $password;
    private $client;
    private $session_id;

    function __construct($username, $password) {
        $this->password = $password;
        $this->username = $username;
    }

    public function connect() {
        $this->client = new nusoap_client($this->url, 'wsdl');
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

    public function get_entry_list($module_name, $offset = 0, $rows = self::MAX_ROWS) {
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
//    //Optional. The list of fields to be returned in the results
//    'select_fields' => array(
//        'id',
//        'first_name',
//        'last_name',
//    ),
//    //A list of link names and the fields to be returned for each link name
//    'link_name_to_fields_array' => array(
//        array(
//            'name' => 'email_addresses',
//            'value' => array(
//                'id',
//                'email_address',
//                'opt_out',
//                'primary_address'
//            ),
//        ),
//    ),
            //The maximum number of results to return.
          'max_results' => $rows,
            //To exclude deleted records
          'deleted' => 0,
            //If only records marked as favorites should be returned.
          'Favorites' => FALSE,
        );
        $get_entry_list_result = $this->client->call("get_entry_list", $get_entry_list_parameters);
        return $get_entry_list_result;
    }

    public function get_meetings() {
        $get_entry_list_result = $this->get_entry_list(self::MEETINGS);
        $list = array();
        foreach ($get_entry_list_result['entry_list'] as $entry) {
            $list[] = new SugarMeeting($entry['name_value_list']);
        }
        return $list;
    }

    public function get_calls() {
        $get_entry_list_result = $this->get_entry_list(self::CALLS);
        $list = array();
        foreach ($get_entry_list_result['entry_list'] as $entry) {
            $list[] = new SugarCall($entry['name_value_list']);
        }
        return $list;
    }

    public function get_tasks() {
        $get_entry_list_result = $this->get_entry_list(self::TASKS);
        $list = array();
        foreach ($get_entry_list_result['entry_list'] as $entry) {
            $list[] = new SugarTask($entry['name_value_list']);
        }
        return $list;
    }

    /**
     * @return array
     */
    public function get_jcrmtime($offset = 0, $rows = self::MAX_ROWS) {
        $get_entry_list_result = $this->get_entry_list(self::JCRMTIME, $offset, $rows);
        $list = array();
        foreach ($get_entry_list_result['entry_list'] as $entry) {
            $list[] = new SugarJCRMTime($entry['name_value_list']);
        }
        return $list;
    }

    public function get_cases($offset = 0, $rows = self::MAX_ROWS) {
        $get_entry_list_result = $this->get_entry_list(self::CASES, $offset, $rows);
        $list = array();
        foreach ($get_entry_list_result['entry_list'] as $entry) {
            $list[] = new SugarCase($entry['name_value_list']);
        }
        return $list;
    }

    public function get_accounts($offset = 0, $rows = self::MAX_ROWS) {
        $get_entry_list_result = $this->get_entry_list(self::ACCOUNTS, $offset, $rows);
        $list = array();
        foreach ($get_entry_list_result['entry_list'] as $entry) {
            $list[] = new SugarAccount($entry['name_value_list']);
        }
        return $list;
    }

    public function get_vehicles($offset = 0, $rows = self::MAX_ROWS) {

        $get_entry_list_result = $this->get_entry_list(self::ACCOUNTS, $offset, $rows);

        $list = array();

        foreach ($get_entry_list_result['entry_list'] as $entry) {
            $list[] = new SugarVehicle($entry['name_value_list']);
        }

        return $list;

    }

}