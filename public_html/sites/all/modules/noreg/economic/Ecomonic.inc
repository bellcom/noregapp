<?php

class Ecomonic {
    const wsdlUrl = 'https://api.e-conomic.com/secure/api1/EconomicWebservice.asmx?WSDL';

    private $agreementNumber;
    private $username;
    private $password;
    private $client = NULL;

    function __construct($agreementNumber, $username, $password) {
        $this->agreementNumber = $agreementNumber;
        $this->password = $password;
        $this->username = $username;
    }

    /**
     * Connect to e-conomic service.
     * @return SoapClient
     */
    public function connect() {
        $this->client = new SoapClient(self::wsdlUrl, array(
            "trace" => 1,
            "exceptions" => 1
          ));
        $this->client->Connect(array(
          'agreementNumber' => $this->agreementNumber,
          'userName' => $this->username,
          'password' => $this->password
        ));

        return $this->client;
    }

    /**
     * Disconnect from e-conomic service
     * @throws Exception
     */
    public function disconnect() {
        if ($this->client != NULL) {
            $this->client->Disconnect();
        }
        else {
            throw new Exception("Not connected.");
        }
    }

    /**
     * Get all debtor handles.
     * @return array
     * @throws Exception
     */
    public function debtor_GetAll() {
        if ($this->client != NULL) {
            $debtorHandles = $this->client->Debtor_GetAll()->Debtor_GetAllResult->DebtorHandle;
            return $debtorHandles;
        }
        else {
            throw new Exception("Not Connected.");
        }
    }

    /**
     * Get all debtor data.
     * @return array
     * @throws Exception
     */
    public function debtor_GetDataArray() {
        if ($this->client != NULL) {
            $debtorHandles = $this->debtor_GetAll();
            $debtorDataObjects = $this->client->Debtor_GetDataArray(array('entityHandles' => $debtorHandles))->Debtor_GetDataArrayResult->DebtorData;
            return $debtorDataObjects;
        }
        else {
            throw new Exception("Not Connected.");
        }
    }

    /**
     * Returns handles for all debtor groups.
     * @return array
     */
    public function debtorGroup_GetAll() {
        if ($this->client != NULL) {
            $debtorGroupHandles = $this->client->debtorGroup_GetAll()->DebtorGroup_GetAllResult->DebtorGroupHandle;
            return $debtorGroupHandles;
        }
        else {
            throw new Exception("Not Connected.");
        }
    }

    public function debtor_GetData($entityHandle) {
        if ($this->client != NULL) {
            $debtorDataObject = $this->client->Debtor_GetData(array('entityHandle' => $entityHandle))->Debtor_GetDataResult;
            return $debtorDataObject;
        }
        else {
            throw new Exception("Not Connected.");
        }
    }

    /**
     * Finds debtor by number and returns its handle.
     * @param $number
     * @return stdClass
     * @throws Exception
     */
    public function debtor_FindByNumber($number) {
        if ($this->client != NULL) {
            $debtorHandle = $this->client->Debtor_FindByNumber(array('number' => $number))->Debtor_FindByNumberResult;
            return $debtorHandle;
        }
        else {
            throw new Exception("Not Connected.");
        }
    }

    /**
     * Creates a new debtor from a data object.
     * The data object that specifies the properties of the new debtor
     * @param $data
     * @throws Exception
     */
    public function debtor_CreateFromData($data) {
        try {
            $debtorGroupHandles = $this->debtorGroup_GetAll();
            $firstDebtorGroup = $debtorGroupHandles[0];
            $newDebtorHandle = $this->client->Debtor_Create(array(
              'number' => $data['uid'],
              'debtorGroupHandle' => $firstDebtorGroup,
              'name' => $data['name'],
              'vatZone' => 'EU'
            ))->Debtor_CreateResult;
            $this->client->Debtor_SetEmail(array(
                'debtorHandle' => $newDebtorHandle,
                'value' => $data['mail']
              )
            );

            if (!empty($data['address'])) {
                $this->client->Debtor_SetAddress(array(
                    'debtorHandle' => $newDebtorHandle,
                    'value' => $data['address']
                  )
                );
            }
            if (!empty($data['postalcode'])) {
                $this->client->Debtor_SetPostalCode(array(
                    'debtorHandle' => $newDebtorHandle,
                    'value' => $data['postalcode']
                  )
                );
            }
            if (!empty($data['city'])) {
                $this->client->Debtor_SetCity(array(
                    'debtorHandle' => $newDebtorHandle,
                    'value' => $data['city']
                  )
                );
            }
            if (!empty($data['country'])) {
                $this->client->Debtor_SetCountry(array(
                    'debtorHandle' => $newDebtorHandle,
                    'value' => $data['country']
                  )
                );
            }
        } catch (Exception $exception) {
            throw $exception;
        }
    }

    /**
     * Sets the name of a debtor.
     * @param $debtorhandle
     * @param $value
     *
     * @throws Exception
     */
    public function debtor_SetName($debtorhandle, $value) {
        if ($this->client != NULL) {
            $this->client->Debtor_SetName(array(
                'debtorHandle' => $debtorhandle,
                'value' => $value
              )
            );
        }
        else {
            throw new Exception("Not Connected.");
        }
    }

    /**
     * Set the email of a debtor.
     * @param $debtorhandle
     * @param $value
     *
     * @throws Exception
     */
    public function debtor_SetEmail($debtorhandle, $value) {
        if ($this->client != NULL) {
            $this->client->Debtor_SetEmail(array(
                'debtorHandle' => $debtorhandle,
                'value' => $value
              )
            );
        }
        else {
            throw new Exception("Not Connected.");
        }
    }

    public function debtor_SetAddress($debtorhandle, $value) {
        if ($this->client != NULL) {
            $this->client->Debtor_SetAddress(array(
                'debtorHandle' => $debtorhandle,
                'value' => $value
              )
            );
        }
        else {
            throw new Exception("Not Connected.");
        }
    }

    public function debtor_SetPostalCode($debtorhandle, $value) {
        if ($this->client != NULL) {
            $this->client->Debtor_SetPostalCode(array(
                'debtorHandle' => $debtorhandle,
                'value' => $value
              )
            );
        }
        else {
            throw new Exception("Not Connected.");
        }
    }

    public function debtor_SetCity($debtorhandle, $value) {
        if ($this->client != NULL) {
            $this->client->Debtor_SetCity(array(
                'debtorHandle' => $debtorhandle,
                'value' => $value
              )
            );
        }
        else {
            throw new Exception("Not Connected.");
        }
    }

    public function debtor_SetCountry($debtorhandle, $value) {
        if ($this->client != NULL) {
            $this->client->Debtor_SetCountry(array(
                'debtorHandle' => $debtorhandle,
                'value' => $value
              )
            );
        }
        else {
            throw new Exception("Not Connected.");
        }
    }


    /**
     * Return debtorhandles for specific user
     * @param $debtorHandle
     *
     * @return mixed
     * @throws Exception
     */
    public function debtor_GetEntries($debtorHandle) {
        if ($this->client != NULL) {
            $entriesHandle = $this->client->Debtor_GetEntries(array('debtorHandle' => $debtorHandle))->Debtor_GetEntriesResult;//->DebtorEntryHandle;
            if (count((array) $entriesHandle) == 0) {
                return NULL;
            }
            return $entriesHandle->DebtorEntryHandle;
        }
        else {
            throw new Exception("Not Connected.");
        }
    }

    /**
     * Get data for specified entries
     * @param $entriesHandle
     *
     * @return mixed
     * @throws Exception
     */
    public function entry_GetDataArray($entriesHandle) {
        if ($this->client != NULL) {
            $entriesDataObjects = $this->client->Entry_GetDataArray(array('entityHandles' => $entriesHandle))->Entry_GetDataArrayResult;
            if (count((array) $entriesDataObjects) == 0) {
                return NULL;
            }
            return $entriesDataObjects->EntryData;
        }
        else {
            throw new Exception("Not Connected.");
        }
    }


    /**
     * Gets the invoice number of the debtor entry
     * @param $debtorEntryHandle
     *
     * @return null | int
     * @throws Exception
     */
    public function debtorEntry_GetInvoiceNumber($debtorEntryHandle) {
        if ($this->client != NULL) {
            $invoiceNumber = $this->client->DebtorEntry_GetInvoiceNumber(array('debtorEntryHandle' => $debtorEntryHandle))->DebtorEntry_GetInvoiceNumberResult;
            if (count((array) $invoiceNumber) == 0) {
                return NULL;
            }
            return $invoiceNumber;
        }
        else {
            throw new Exception("Not Connected.");
        }
    }

    public function getAgreementNumber() {
        return $this->agreementNumber;
    }

    public function getPassword() {
        return $this->password;
    }

    public function getUsername() {
        return $this->username;
    }

    public function getClient() {
        return $this->client;
    }
}
