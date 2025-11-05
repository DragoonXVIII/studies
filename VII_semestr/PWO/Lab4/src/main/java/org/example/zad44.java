package org.example;

public class zad44 {
}

public Ticket createTicket(Ticket ticket) {
    if (loadTicket(ticket.getId()) instanceof Ticket) {
        throw new TicketAlreadyExistsException("Ticket with ID " + ticket.getId() + " already exists");
    }
    Ticket savedTicket = saveTicket(ticket);
    if (savedTicket == null) {
        throw new TicketPersistenceException("Failed to persist ticket with ID " + ticket.getId());
    }
    return savedTicket; //TICKET PERSISTED????
}




public void processMovie(Movie movie) {
    try {
        movieProcessor.process(movie);
    } catch (ProcessException e) {
        throw e;
    } catch (Exception e) {
        throw new MovieProcessingException("Unexpected error while processing movie: " + movie.getTitle(), e);
    } finally {
        movieProcessor.close();
    }
}




public void validatePaymentCard(String cardNumber) {
    if (!cardRepository.verifyExpirationDate(cardNumber)) {
        throw new ValidationException("Payment card " + cardNumber + " is expired");
    } //???
}




public Invoice createInvoice(Invoice invoice) {
    if (invoiceRepository.findById(invoice.getId()) != null) {
        throw new InvoiceAlreadyExistsException("Invoice with ID " + invoice.getId() + " already exists");
    }
    return invoiceRepository.save(invoice);
}

public Invoice editInvoice(int invoiceId, Invoice newInvoiceData) {
    Invoice existingInvoice = invoiceRepository.findById(invoiceId);
    if (existingInvoice == null) {
        throw new InvoiceNotFoundException("Invoice with ID " + invoiceId + " not found");
    }
    existingInvoice.updateFrom(newInvoiceData);
    return invoiceRepository.save(existingInvoice);
}
