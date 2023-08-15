module Components {

    @ Service specifically for deployables subsystem
    active component DeployablesService {

        # ----------------------------------------------------------------------
        # Ports
        # ----------------------------------------------------------------------
        @ Port for receiving status from feedback switch query 
        sync input port deployableFeedbackSwitchPort: StringValue

        @ Port for toggling a burnwire
        output port deployableToggleBurnwirePort: StringValue

        # ----------------------------------------------------------------------
        # Commands
        # ----------------------------------------------------------------------
        async command ActivateDeploymentSequence

        # ----------------------------------------------------------------------
        # Events
        # ----------------------------------------------------------------------
        @ Log recevied feedback switch status 
        event receivedFeedbackSwitchStatus(target_component: string, switch_state: string) \
            severity activity low \
            format "Deployable {} feedback switch status is: {}"

        @ Log when a burnwire is toggled 
        event burnwireToggled(target_component: string, toggle_state: string) \
            severity activity low \
            format "Deployable {} burnwire toggled to: {}"

        @ Log deployable successfully deployed (feedback switch reading is high)
        event deployableDeployed(target_component: string) \
            severity activity low \
            format "Deployable: {} deployment successful!"

        @ Log deployable deployment is pending (burnwire set but awaiting switch reading)
        event deployablePending(target_component: string) \
            severity activity low \
            format "Deployable: {} deployment is pending..."

        @ Log deployable is stowed (feedback switch reading is low)
        event deployableStowed(target_component: string) \
            severity activity low \
            format "Deployable: {} is stowed [not deployed]"
        

        @ Log deployment sequence started 
        event deploymentSequenceStarted () \
            severity activity low \
            format "Deployment sequence started"

        @ Log deployment sequence ended
        event deploymentSequenceEnded() \
            severity activity low \
            format "Deployment sequence ended"






        # ----------------------------------------------------------------------
        # Parameters
        # ----------------------------------------------------------------------


        ###############################################################################
        # Standard AC Ports: Required for Channels, Events, Commands, and Parameters  #
        ###############################################################################
        @ Port for requesting the current time
        time get port timeCaller

        @ Port for sending command registrations
        command reg port cmdRegOut

        @ Port for receiving commands
        command recv port cmdIn

        @ Port for sending command responses
        command resp port cmdResponseOut

        @ Port for sending textual representation of events
        text event port logTextOut

        @ Port for sending events to downlink
        event port logOut

        @ Port for sending telemetry channels to downlink
        telemetry port tlmOut

        @ Port to return the value of a parameter
        param get port prmGetOut

        @Port to set the value of a parameter
        param set port prmSetOut

    }
}